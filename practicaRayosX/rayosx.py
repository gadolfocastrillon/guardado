import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

data = pd.read_csv('MnO2.csv', skiprows=range(27), on_bad_lines='skip')
df = pd.DataFrame(data,columns=['Angle','Intensity'])
pico_angle = [] 
pico_intensidad = []

lambda_rayosX = 1.54 #m Por ahora. 
k = 0.89 


for i in range(len(df['Angle'])):
	angulo = df['Angle'][i]
	if ((df['Angle'][i]<29)and(df['Angle'][i]>28)): 
		pico_angle.append(df['Angle'][i]) 
		pico_intensidad.append(df['Intensity'][i])

max_ = max(pico_intensidad)
saved_intensidad = []
saved_angle = []  
for i in range(len(pico_intensidad)): 
	if (pico_intensidad[i] == max_): 
		for j in range(-2,3,1):
			saved_intensidad.append(pico_intensidad[i+j])
			saved_angle.append(pico_angle[i+j])

ancho = saved_angle[4] - saved_angle[1]


def y_calculo(angle): 
	global ancho 
	return ancho*np.cos(angle)

def x_calculo(angle): 
	return 4*np.sin(angle)

def linea(x,m,x0): 
	return m*x + x0

x = [] 
y = []
for i in range(len(saved_angle)): 
	x.append(-x_calculo(saved_angle[i]))
	y.append(-y_calculo(saved_angle[i]))

parametros, error = curve_fit(linea,x,y)
dat = [] 
for i in x: 
	dat.append(linea(i,*parametros))
size = k*lambda_rayosX/parametros[1]
strain = parametros[0]

print("Size = " +str(size)+ " , strain = "+str(strain))

'''
plt.figure()
plt.plot(x,y,'.')
plt.plot(x,dat)
#plt.show()
'''
print("Valores alrededor del ancho")
print(saved_intensidad)
print("\nEl Ancho del valor medio del pico mas grandes es: " + str(ancho))
print("\n")
plt.figure(figsize=(10,7)) 
plt.plot(df['Angle'],df['Intensity'],'k')
plt.title("Difracción de rayos x para el MnO2")
plt.xlabel('Angulo')
plt.ylabel('Intensidad')
plt.grid()
plt.savefig("Grafico_MnO2.svg")
#plt.show()
