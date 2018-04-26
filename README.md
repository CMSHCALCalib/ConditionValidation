# ConditionValidation
These are simple root marcos. 

  How use them:

  0) 
     First of all, you have to exctract condition from DB.
     It can be done using  scrpit, which you can excute as follows:
     
      ./makeDump.csh Pedestals HcalPedestals_ADC_v8.0_hlt  306463  frontier://FrontierProd/CMS_CONDITIONS
      
      where 'Pedestals' is a condition type, "HcalPedestals_ADC_v8.0_hlt" name of the condition in CondDB,  
      "306463" is run number from which the calibration is valid, i.e. an interval of validity (IOV)
      Caveat: Check geometry inside the script. Otherwise you will get in a crash at best, 
      or some channels will be missing silently.    

  1)
    The name of marco reflects the HCAL condition object it was created to compare for. 
    For instance, let's  consider how to make comaprison HcalRespCorrs.
    Fist, you should open the macro and  put paths to the files that you want to compare.
    Second, you can adjust  z-ranges of ratio maps.
    Third, you can change a range that defines outlier channels.
    These can be done at begining function compare(), which is right some "#include" lines.

  2) 
    root
    .L  RespCorrs.C
    compare()

    It will produce 3 plots of ratio maps(HB&HO, HE, HF) and list outlier channel. 
    Caveat: Pedestals  and ZeroSuppresionThreshold plot differences.

   Note:  ChannelQualty.C produces a'txt' file, that contains bad channels in both files,
          highlighting lines with different channel status   
   Note: The Pedetals.C  produces difference maps, while other tools produce ratio maps.


  Utils:
  
    1) In order to compare calibrations in common you can use tool (RespCorrsXGains.C) that 
    produces product of Gains and RespCorrs. It produces txt file, which can be further processed
    by RespCorrs.C 
    2) The script "redump.csh" re-dumping the input condtion. The procedure allow to reveal incorrect lines, characters, and conflicts input files giving various warnings. The other useful feature is that the re-dumped condition has the standard channel order, spacing.
