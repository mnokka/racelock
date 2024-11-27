Qt POC for running(etv) races racelock replacement (like in https://raceclock.com/)

This clock give possibility ro have rolling starting for competitors
-user adds BIB m and send delay between competitors starts
-log file have all data for parsing start times for result calculations (time, BIB)

Example of log file:

16:56:26 --> Created initial log file: RACE_CLOCK_2023-03-11_16-56-26.log
16:56:26 --> Send delay:15  Bib:none
16:56:31 --> Lights, Bib: none -->READY
16:56:41 --> Lights, Bib: none -->GO
16:56:43 --> Lights, Bib: none -->WAIT
16:56:47 --> Lights, Bib: none -->READY
16:56:56 --> Bib number: 123 added
16:56:57 --> Lights, Bib: 123 -->GO
16:56:59 --> Lights, Bib: 123 -->WAIT
16:57:03 --> Lights, Bib: 123 -->READY

Short video on running included
