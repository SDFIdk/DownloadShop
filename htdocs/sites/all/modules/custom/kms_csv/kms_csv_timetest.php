 <?php
 $beginOfDay = strtotime("midnight - 1 day", time());
 $endOfDay   = strtotime("tomorrow", $beginOfDay) - 1;

 print("ACtual timestamp".time()." begin - ".$beginOfDay." end - ".$endOfDay);
