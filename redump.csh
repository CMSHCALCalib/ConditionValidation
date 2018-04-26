#!/bin/csh
cmsenv

cat >! temp_dump_cfg.py <<%

import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.Eras import eras
process = cms.Process('DUMP',eras.Run2_2018)

#process = cms.Process("DUMP")
process.load("CondCore.CondDB.CondDB_cfi")


process.load("Configuration.Geometry.GeometryExtended2018_cff")
process.load("Configuration.Geometry.GeometryExtended2018Reco_cff")


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
)

process.source = cms.Source("EmptySource",
    numberEventsInRun = cms.untracked.uint32(1),
    firstRun = cms.untracked.uint32(1)
)

process.hcal_db_producer = cms.ESProducer("HcalDbProducer",
    dump = cms.untracked.vstring(''),
    file = cms.untracked.string('')
)


#--------------------- replacing conditions, fileinpath starts from /src 
process.es_ascii = cms.ESSource("HcalTextCalibrations",
   input = cms.VPSet(
       cms.PSet(
           object = cms.string('$1'),
           file = cms.FileInPath('$2')
      )
   )
)
process.es_prefer = cms.ESPrefer('HcalTextCalibrations','es_ascii')


process.dumpcond = cms.EDAnalyzer("HcalDumpConditions",
       dump = cms.untracked.vstring("$1")
)
process.p = cms.Path(process.dumpcond)
%
cmsRun temp_dump_cfg.py
rm temp_dump_cfg.py
