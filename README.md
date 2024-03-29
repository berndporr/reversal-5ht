![alt tag](bna/results_v4.png)

## Reversal learing without reward prediction error

### Stimuli

 * Visual landmark (dark green and bright green objects)
 * Place fields around them
 * Reward signal at the landmark which can be assigned to one of the landmarks
 * Switching of the reward from one landmark to the other (reversal)
 * Reward delivery can be delayed for delayed reward paradigms

### Motor output
 * Two signals to either approach the dark green landmark or the bright one

### Compile under Linux
 * Install these packages by typing in the commandline: `sudo apt-get install qt5-qmake g++ qtbase5-dev-tools qtdeclarative5-dev-tools qtbase5-dev qt5-default libquicktime-dev`
 * Clone it from this reposity with `git clone <git URL from the top of this page>`.
 * `cd reversal-5ht`
 * `qmake`
 * `make`

### How to run?

Just type `./reversal-5ht` for the default settings.

There are two different modes: single run (-a) and statistical run (-b).

The option -p selects the different scenarios (see below) which cause a lack of
5HT and different options to fix it. With the -p option subdirectories are
created according to the scenario.

```
./reversal-5ht: command line options
 -a:            single food run
 -b:            statistics
 -f max:        max contacts to the landmark with food for stats
 -q:            quicktime export
 -n:            no graphical output
 -p scenario #: experimental scenario
Possible scenarios:
0 : Normal condition (/normal/)
1 : DRN is suppressed (/drn_suppress/)
2 : DRN is suppressed and SSRI (/drn_suppress_ssri/)
3 : DRN is suppressed and 5HTR2 up (/drn_suppress_5ht2up/)
```

Do run stats of all scenarios type:
```run_all_stats.sh``` and then plot the results with
```plot_reversal.py```.
