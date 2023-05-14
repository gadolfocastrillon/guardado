#include <iostream>
#include <stdio.h>
#include <item.h>
int menu(item shop){
	int i ; 
	shop.initial(); 
	cout<<"\n ¿Qué quieres hacer?"<<endl; 
	cout<<"\n1: Añadir un nuevo item"; 
	cout<<"\n2: Eliminar un item."; 
	cout<<"\n3: Vender un item."; 
	cout<<"\n4: Mostrar todos los items"; 
	cout<<"\n5: Salir."<<endl; 
	cout<<"\n\n Ingrese un numero:"; 
	cin>>i; 
	switch(i){
		
		case 1: 
			shop.add_(); 
			break; 
		case 2: 
			shop.delete_(); 
			break; 
		case 3: 
			shop.sell_(); 
			break; 
		case 4: 
			shop.display_(); 
			break; 
		case 5: 
			cout<<"Adios! Gracias."; 
			break; 

	}
	return i; 
}



int main(){
	int i; 
	item shoping_mall; 
	system("clear"); 
	i = menu(shoping_mall); 
	if (i==5){
		system("clear"); 
	}
	cin.get(); 
	return 0; 	
}