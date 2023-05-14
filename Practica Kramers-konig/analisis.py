import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt  
from scipy.signal import medfilt 

lim = 300  #Tenemos 300 datos hasta el 280
lim2 = 200 #Tenemos 200 datos despues del 850 

Window_size = 201

#cargado de la señal oscura de la referencia. 
referencia_dark = r'GustavoKevin/Al.Master.dark'
referencia_luz =  r'GustavoKevin/Al.Master.reference'
nombre_aluminio =  r'GustavoKevin/Al.Master.scope'
nombre_cobre =  r'GustavoKevin/Cu.Master.scope'
nombre_dcobre =  r'GustavoKevin/CuO.Master.scope'
nombre_silicio =  r'GustavoKevin/Si.Master.scope'

f = pd.read_csv(referencia_dark, sep='\t',skiprows=14, skipfooter=1,engine='python')
Ir = np.array(f)[lim:-lim2,1] #Aplico esto para filtrar la segunda fila de los datos. 
wld = np.array(f)[lim:-lim2,0]
f = pd.read_csv(referencia_luz, sep='\t',skiprows=14, skipfooter=1,engine='python')
Ireferencia = np.array(f)[lim:-lim2,1]
#Aluminio
f = pd.read_csv(nombre_aluminio, sep='\t',skiprows=14, skipfooter=1,engine='python')
Ial = np.array(f)[lim:-lim2,1]
#Cobre
f = pd.read_csv(nombre_cobre, sep='\t',skiprows=14, skipfooter=1,engine='python')
Icu = np.array(f)[lim:-lim2,1]
#Dioxido de cobre
f = pd.read_csv(nombre_dcobre, sep='\t',skiprows=14, skipfooter=1,engine='python')
Icuo = np.array(f)[lim:-lim2,1]
#Silicio
f = pd.read_csv(nombre_silicio, sep='\t',skiprows=14, skipfooter=1,engine='python')
Isi = np.array(f)[lim:-lim2,1]


#Se hace un filtrado del espectro y la referencia
Ireferencia=medfilt(medfilt(Ireferencia,kernel_size=Window_size))
Ial=medfilt(medfilt(Ial,kernel_size=Window_size))
Icu=medfilt(medfilt(Icu,kernel_size=Window_size))
Icuo=medfilt(medfilt(Icuo,kernel_size=Window_size))
Isi=medfilt(medfilt(Isi,kernel_size=Window_size))

#Calculo el valor de la reflectancia 
R1 = (Ial-Ir)/(Ireferencia - Ir)
R2 = (Icu-Ir)/(Ireferencia - Ir)
R3 = (Icuo-Ir)/(Ireferencia - Ir)
R4 = (Isi-Ir)/(Ireferencia - Ir)

'''
plt.figure()
plt.plot(wld,R1)
plt.show()
'''

#wn2d = 1/wld[::-1]
#lnr = np.log(R1)/2
#dn = np.zeros(len(wn2d))
#h = wn2d[1] - wn2d[0]

def funcion(wld,R):
	wn2d = 1/wld[::-1]
	lnr = np.log(R)/2
	dn = np.zeros(len(wn2d))
	h = wn2d[1] - wn2d[0]
	for ii in range(len(wn2d)): 
		if(ii%2 == 0): 
			f = 0 
			for jj in range(1,len(wn2d),2): 
				f = f + wn2d[ii]*lnr[jj]/(wn2d[jj]**2 - wn2d[ii]**2)
		else: 
			f = 0 
			for jj in range(0,len(wn2d),2): 
				f = f + wn2d[ii]*lnr[jj]/(wn2d[jj]**2 - wn2d[ii]**2)
		
		dn[ii] = 2*2*h/np.pi*f
		phaser = -dn
	nn=(1-R**2)/(1+R**2-2*R*np.cos(phaser))
	kk=2*R*np.sin(phaser)/(1+R**2-2*R*np.cos(phaser))
	return nn,kk

def graficador(n,k,lon,nombre='Inserte el nombre del grafico'): 
	plt.figure(figsize=(10,7))
	plt.plot(lon,n,"#ff0000",label='n experimental')
	plt.plot(lon,k,"#00ff00",label='k experimental')
	plt.title(nombre)
	plt.legend()
	plt.xlabel("$\lambda$ (nm)")
	plt.grid()
	plt.show()

n1,k1 = funcion(wld,R1)
n2,k2 = funcion(wld,R2)
n3,k3 = funcion(wld,R3)
n4,k4 = funcion(wld,R4)

#graficador(n1,k1,wld,nombre='Valores experimentales para el aluminio')
#graficador(n2,k2,wld,nombre='Valores experimentales para el cobre')
#graficador(n3,k3,wld,nombre='Valores experimentales para el dioxido de cobre')
graficador(n4,k4,wld,nombre='Valores experimentales para el silicio') 