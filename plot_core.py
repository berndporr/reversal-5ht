#!/usr/bin/python3

import numpy as np
import pylab as pl
#
data = np.loadtxt('log.dat');
#
fig = pl.figure(1)
#
a = 0
b = len(data[:,0])
# compound
pl.subplot(911);
pl.plot(data[a:b,0],data[a:b,26]);
pl.plot(data[a:b,0],data[a:b,6]);
pl.plot(data[a:b,0],data[a:b,7]);
pl.ylabel('visR*2/PF');
#
pl.subplot(912);
pl.plot(data[a:b,0],data[a:b,30]);
pl.ylabel('w OFC');
#
pl.subplot(913);
pl.plot(data[a:b,0],data[a:b,31]);
pl.plot(data[a:b,0],data[a:b,32]);
pl.ylabel('mPFC w G/B');
#
pl.subplot(914);
pl.plot(data[a:b,0],data[a:b,9]);
pl.ylabel('mPFC G');
#
pl.subplot(915);
pl.plot(data[a:b,0],data[a:b,10]);
pl.ylabel('mPFC B');
#
pl.subplot(916);
pl.plot(data[a:b,0],data[a:b,14]);
pl.ylabel('VTA');
#
pl.subplot(917);
pl.plot(data[a:b,0],data[a:b,28]);
pl.ylabel('OFC');
#
pl.subplot(918);
pl.plot(data[a:b,0],data[a:b,25]);
pl.ylabel('DRN');
#
pl.subplot(919);
pl.plot(data[a:b,0],data[a:b,29]);
pl.ylabel('5HT');
#
#
pl.show();
