# ConditionValidation
These are simple root marcos. 


  How use them:

  0)
    Name of marco reflects the HCAL condition object it was created to compare  
    For instance, let's  consider how to make comaprison HcalRespCorrs.
    Fist, you should open the macro and  put paths to files that you want to compare()
    Second, you can adjust  z-ranges of ratio maps
    Third, you can change a range that defines outlier channel.
    These can be done at begining function compare(), which is  right some "#include" lines.

1) 
    root
    .L  RespCorrs.C
    compare()

    It will produce 3 plots of ratio maps(HB&HO, HE, HF) and list outlier channel. 
    Caveat: Pedestals  and ZeroSuppresionThreshold plot differences.  
