# -*- coding: utf-8 -*-
"""
Created on Wed May 27 17:27:39 2020

@author: marcelo
"""

from math import sin, pi
import numpy as np

Ts = 10 * 10 ** -5
Fs = 1 / Ts
T_sim = 1
L = round(T_sim/Ts)
t = np.zeros((L))

for i in range(L):
    t[i] = (i+1)

trig1 = np.zeros((L)) 
trig2 = np.zeros((L))
trig = np.zeros((L))
trig_n = np.zeros((L))
vref = np.zeros((L))
cmd = np.zeros((L))
v = np.zeros((L))


for k in range(1, L):
    v[k] = 0.4 * sin(2 * pi * (1 / Fs) * t[k])
    trig1[k] = trig1[k-1] + 1
    
    if trig1[k] > 100:
        trig1[k] = 1
    
    trig2[k] = 100 - trig1[k]
    
    if trig1[k] < 50:
        trig[k] = trig1[k]
    else:
        trig[k] = trig2[k]
    
    trig_n[k] = (1/50) * trig[k]
    
    vref[k] = 0.5 + v[k]
    
    if vref[k] > trig_n[k]:
        cmd[k] = 1
    else:
        cmd[k] = 0
        
