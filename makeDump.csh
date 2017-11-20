#!/bin/csh
cmsenv

if ("$4" == "test") then
     echo "connectstring = sqlite_file:test.db"
     set connectstring = sqlite_file:test.db
else  if ( $#argv == 3 ) then
    echo "connectstring = frontier://FrontierProd/CMS_CONDITIONS"
    set connectstring = frontier://FrontierProd/CMS_CONDITIONS
else
    echo "connectstring = $4"
    set connectstring = $4
endif

cat >! temp_dump_cfg.py <<%

import FWCore.ParameterSet.Config as cms

process = cms.Process("DUMP")
#process.load("Configuration.Geometry.GeometryExtended2016_cff")
#process.load("Configuration.Geometry.GeometryExtended2016Reco_cff")

process.load("Configuration.Geometry.GeometryExtended2017Plan1_cff")
process.load("Configuration.Geometry.GeometryExtended2017Plan1Reco_cff")

#process.load("Configuration.Geometry.GeometryExtended2018_cff")
#process.load("Configuration.Geometry.GeometryExtended2018Reco_cff")


#process.load("Configuration.Geometry.GeometryExtendedReco_cff")

process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
from Configuration.AlCa.autoCond import autoCond
process.GlobalTag.globaltag = autoCond["phase1_2017_realistic"]


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
)

process.source = cms.Source("EmptySource",
    numberEventsInRun = cms.untracked.uint32(1),
    firstRun = cms.untracked.uint32($3)
)

process.hcal_db_producer = cms.ESProducer("HcalDbProducer",
    dump = cms.untracked.vstring(''),
    file = cms.untracked.string('')
)

process.load("CondCore.CondDB.CondDB_cfi")
process.CondDB.connect = '$connectstring'

process.es_pool = cms.ESSource("PoolDBESSource",
                                      process.CondDB,
                                      timetype = cms.string('runnumber'),
                                      toGet = cms.VPSet(cms.PSet(record = cms.string("Hcal$1Rcd"),
                                                                 tag = cms.string("$2")
                                                                 )
                                                        )
                                      )

process.es_prefer_es_pool = cms.ESPrefer( "PoolDBESSource", "es_pool" )

process.dumpcond = cms.EDAnalyzer("HcalDumpConditions",
                                  dump = cms.untracked.vstring("$1")
                                  )

process.p = cms.Path(process.dumpcond)

%
cmsRun temp_dump_cfg.py
rm temp_dump_cfg.py
%
