#include <item.h>
#include <iostream>

void mensaje(int total_price){
		if (total_price!=0){
			cout<<"\nEl gasto total es : "; 
			cout<<total_price<<" Yens"<<"\n Gracias.";
					}
		cout<<"Bye...bye..."; 
	}

void item::add_(void){
	const int j = 20;
	system("clear"); 
	/*
	cout<<"\nIngrese la categoria del item : "; 
	//cin>>name[z]; 
	getline(cin,name[z]);
	cout<<"\nIngrese el codigo del item : "; 
	//cin>> code[z]; 
	getline(cin,code[z]);
	cout<<"Ingrese el precio del item : "; 
	//cin>>price[z]; 
	getline(cin,price[z]);
	*/
	cout<<"Corregir el como se añaden los datos"<<endl; 
	z++; 
}

void item::delete_(void){
	int i,j; 
	system("clear"); 
	cout<<"\n por favor ingrese el codigo del item : "; 
	cin>>i; 
	for(j=0;j<z;j++){
		if(code[j] == i){
			price[j] = 0; 
			cout<<"\nEl item fue eliminado de la lista."; 
			cin.get(); 
			break; 
		}
	}
}
void item:: sell_(void){
	char a; 
	int i,j; 
	float total_price=0; 
	system("clear"); 

	
		
	cout<<"\nIngrese el codigo del item : "; 
	cin>>i; 
	for(j=0;j<z;j++){
		if(code[j] == i){
			if (price[j] == 0){
				cout<<"\nLo sentimos. No queda ningún articulo en esta categoria"; 
				cout<<"\n¿Quieres comprar otro item? y\\n"<<endl; 
				cin>>a; 
				if(a=='y' or a=='Y'){
					cout<<"\nIngrese el codigo del item : ";
					cin>>i; 
					j=-1; 
				}
				else{
					mensaje(total_price);
					break; 
				}
			}
			else{
				cout<<"La categoria del item es : "<<name[j];
				cout<<"\nEl precio del item es :"<<price[j]<<" yens."<<endl; 
				total_price+=price[j]; 
				price[j]=0; 
				cout<<"\nDeseas comprar otro item: y\\n"; 
				cin>>a; 
				if((a=='y')or (a=='Y')){
					cout<<"\nIngrese el codigo del item : "; 
					cin>>i; 
					j=-1; 
				}
				else{
					system("clear"); 
					mensaje(total_price);
					break; 

				}
			}

		}
	}
	cin.get();
}

void item::display_(){
	int i,j=1; 
	system("clear"); 

	for(i=0;i<z;i++){
		cout<<j<<".Item category is: "<<name[i]<<endl; 
		cout<<"Item code is: "<<code[i]<<endl; 
		cout<<"Item price is: "<<price[i]<<" yens."<<endl;
		j++;
		cin.get(); 
	}
}