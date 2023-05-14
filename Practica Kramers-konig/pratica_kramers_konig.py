import numpy as np 
import pandas as pd  



#Puntos de referencia 
archivo = np.loadtxt('GustavoKevin/Al.Master.reference', skiprows=14)
df_reference = pd.DataFrame(archivo,columns=['lambda','Intensidad'])
archivo = np.loadtxt('GustavoKevin/Al.Master.dark', skiprows=14)
df_dark = pd.DataFrame(archivo,columns=['lambda','Intensidad'])

#Datos del Aluminio
archivo = np.loadtxt('GustavoKevin/Al.Master.scope', skiprows=14)
df_Al = pd.DataFrame(archivo,columns=['lambda','Intensidad'])

#Datos del cobre 
archivo = np.loadtxt('GustavoKevin/Cu.Master.scope', skiprows=14)
df_Cu = pd.DataFrame(archivo,columns=['lambda','Intensidad'])

#Datos del dioxido de cobre
archivo = np.loadtxt('GustavoKevin/CuO.Master.scope', skiprows=14)
df_CuO = pd.DataFrame(archivo,columns=['lambda','Intensidad'])

#Datos del silicio
archivo = np.loadtxt('GustavoKevin/Si.Master.scope', skiprows=14)
df_Si = pd.DataFrame(archivo,columns=['lambda','Intensidad'])

def limpiado(df,val1,val2): 
	n = int (len(df))
	valor1 = 0 
	valor2 = 0 

	for i in df['lambda']: 
		if(i<=val1): 
			valor1 +=1
		if(i>=val2): 
			valor2 +=1 
	df.drop(df.index[0:valor1], inplace=True)
	n = int(len(df)) 
	df.drop(df.index[n-valor2:n], inplace=True)
	return df 

#Referencia y oscuridad
df_dark = limpiado(df_dark,280,850)
df_reference = limpiado(df_reference,280,850)
#Datos de Aluminio
df_Al = limpiado(df_Al,280,850)
#Datos del cobre 
df_Cu = limpiado(df_Cu,280,850)
#Datos del dioxido de cobre 
df_CuO = limpiado(df_CuO,280,850)
#Datos del Silicio
df_Si = limpiado(df_Si,280,850)


diferencia = df_reference['Intensidad'] - df_dark['Intensidad']
df_Al['diff'] = diferencia 
df_Cu['diff'] = diferencia
df_CuO['diff'] = diferencia
df_Si['diff'] = diferencia

print("Aluminio")
print(df_Al.head())
print("Cobre")
print(df_Cu.head())
print("Oxido de cobre")
print(df_CuO.head())
print("Silicio")
print(df_Si.head())
