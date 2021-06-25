#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>


using namespace std;

bool st[100]={1,1,1,1,1};
bool stuser[100]={1,1,1,1,1,1,1};
double pc[100]={12.35,5.50,13.39,22.40,10.99};
double pv[100]={15.50,7.95,18.55,30.39,14.75};
double subtotal[100];
double subtotal2[100];
double subtotalV1,subtotalV2,totalV,totalV2,cortedecajafinal,cortedecajafinal2;
double corte[100];
double corte2[100];
int cantidadC1[100];
int Ntotal,total=20,Ntotaluser,totaluser=20,NtotaluserV,totaluserV=2,lista=20,encontradoV1=0,venta1,precio_temp1,precio_temp2;
int ii=7,vendido,ic=0,ic2=0,indicecntventa;
int id[100]={2,4,1,3,5};
int existencias[100]={16,18,12,20,30};
int nr[100]={5,6,4,7,8};
int contrasena[100]={123,123,123,123,123,123,123};
int tipo[100]={1,1,1,1,1,2,2};
int sell[100];
int sell2[100];
string nombre[100]={"Leche","Pan","Agua","Huevos","Refresco"};
string resurtirC[100];
string cuentas[20]={"Mario","Ramiro","Sergio","Oswaldo","Martin","Vend1","Vend2"};
string nombreV_temp,nombreusuario_temp,nombreproducto_temp;

void Autenticacion();
void AutenticacionV();
void Administrador();   //prototipos
void Ventas();
void Altas();
void Bajas();
void Consultas();
void Modificaciones();
void Precio_de_compra();
void Precio_de_venta();
void Existencias();
void Nivel_de_reorden();
void Resurtir();
void Mostrar_inventario();
void Por_id();
void Por_producto();
void Administracion_de_cuentas();
void Altas_usuario();
void Bajas_de_usuario();
void Consulta_de_usuario();
void Modificaciones_de_contrasena();
void Mostrar_cuentas();
void Corte_de_caja();
void Vendedor1();
void Vendedor2();
void Ventas_vendedor1();
void Ventas_vendedor2();
void Tpo1();
void Tpo2();
void Clientes2();
void Cortedecaja1();
void Cortedecaja2();
void Imprimir_ticket();
void Imprimir_ticket2();
void Almacenamiento();
void SubtotalV();
void SubtotalVV2();
void Total();
void Total2();
void Almacenamientocorte();
void Almacenamientocorte2();
void Actualizacion_inventario();
void Menor_a_mayor();
void Mayor_a_menor();
void Inicializacion();
void ListaAdmin();
void ListaVend();

int Buscar(string name);
int Buscar_cuentas(string name);
int Buscar_cuentasA(string name);
int Buscar_cuentasV(string name);
int Buscar_id(int name);

struct elemento{
    int id;
    string prod;
    string resurtir;
    double pc;
    double pv;
    int existencias;
    int nr;
    bool st;
};
struct atributos_cuentas{
    string nombre;
    int contrasena;
    bool stuser;
    int tipo;
};

elemento inventario[100];
elemento resurtirA[100];
atributos_cuentas lsA[100];
atributos_cuentas lsV[100];


int main (){
    
    int opcion1;
    
    do{
        cout<<"Menu principal"<<endl;
        cout<<"1. Administrador. "<<endl;
        cout<<"2. Ventas. "<<endl;
        cout<<"3. Salir. "<<endl;
        cout<<"Opcion: ";
        cin>>opcion1;
        switch(opcion1){
            case 1: Administrador();
                break;                                                      
            case 2: Ventas();
                break;
            case 3: cout<<"Cerrando sistema"<<endl;
                break;
            default:cout<<"Valor no valido.";
        };
    }while(opcion1!=3);

    return 0;
}

void Administrador(){
    ListaAdmin();
    ListaVend();
    Autenticacion();
    Inicializacion();
    int opcion2;
    
    do{
        cout<<"Menu Administrador\n";    
        cout<<"1. Altas"<<endl;
        cout<<"2. Bajas"<<endl;
        cout<<"3. Consultas"<<endl;
        cout<<"4. Modificaciones"<<endl;
        cout<<"5. Mostrar inventario"<<endl;
        cout<<"6. Administracion de cuentas de usuarios"<<endl;
        cout<<"7. Corte de caja general"<<endl;
        cout<<"8. Regresar al menu anterior"<<endl;
        cout<<"Opcion: ";
        cin>>opcion2;
        switch(opcion2){
            case 1: Altas();
                break;
            case 2: Bajas();
                break;
            case 3: Consultas();
                break;
            case 4: Modificaciones();
                break;
            case 5: Mostrar_inventario();
                break;
            case 6: Administracion_de_cuentas();
                break;
            case 7: Corte_de_caja();
                break;
            case 8: cout<<" "<<endl;
                break;
            default:cout<<"Valor no valido."<<endl;
        };
    }while(opcion2!=8);
}

void Ventas(){    
    
    ListaVend();
    AutenticacionV();
    if(nombreV_temp=="Vend1") //tengo que modificar el void para más de dos vendedores y pueda hacer el
        Vendedor1();         //corte correctamente.
    else
        Vendedor2();    
}

void Altas(){
    
    int i=Ntotal,indice;
    string nombre_temp;
    
    while(true){                
        cout<<"Producto: ";
        cin>>nombre_temp;
        indice=Buscar(nombre_temp);
        do{       
            inventario[indice].st=1;
            break;
        }while(inventario[indice].prod==nombre_temp);
        if(nombre_temp=="*")
            break;
        if(indice==-1 || inventario[indice].st==0){
            inventario[i].prod=nombre_temp;
            cout<<"Id: ";
            cin>>inventario[i].id;
            do{
                cout<<"PC: ";
                cin>>inventario[i].pc;
                cout<<"PV: ";
                cin>>inventario[i].pv;
                if(inventario[i].pc>inventario[i].pv)
                    cout<<"El precio de venta es menor al precio de compra"<<endl;
            }while(inventario[i].pc>inventario[i].pv); 
            inventario[i].st=1;
            do{
                cout<<"Existencias: ";
                cin>>inventario[i].existencias;
                cout<<"NR: ";
                cin>>inventario[i].nr;
                if(inventario[i].existencias<inventario[i].nr)
                    cout<<"El numero de existencias es menor a numero de reorden"<<endl;
            }while(inventario[i].existencias<inventario[i].nr);
            inventario[i].st=1;
            i++;
        }
        else
            cout<<"Producto activo"<<endl;    
    }        
    Ntotal=i;
}

void Bajas(){
    
    int encontrado,repetido;
    string nombre_temp;    
    
    while(true){
        cout<<"Producto: ";
        cin>>nombre_temp;
        if(nombre_temp=="*")
            break;
        repetido=Buscar(nombre_temp);
        if(inventario[repetido].st!=0){    
            encontrado=Buscar(nombre_temp);
            if(encontrado==-1)
                cout<<"No encontrado"<<endl;
            else{
                inventario[encontrado].st=0;      
                cout<<"Producto dado de baja"<<endl;        
            }  
        }
        else
            cout<<"Inexistente"<<endl;
    }
}   

void Consultas(){
    
    int indice;
    string nombre_temp;
    
    while(true){
    cout<<"Producto: ";
    cin>>nombre_temp;
    if(nombre_temp=="*") //resurtir
        break;
    indice=Buscar(nombre_temp);
    if(indice==-1 || inventario[indice].st==0)
        cout<<"No encontrado"<<endl;
    else{
        cout<<left<<setw(8)<<"Id"<<setw(16)<<"Producto"<<setw(10)<<"PC"<<setw(10)<<"PV"<<setw(13)<<"Existencias"<<setw(25)<<"Nivel de reorden"<<endl;
        cout<<left<<setw(8)<<inventario[indice].id<<setw(16)<<inventario[indice].prod<<setw(10)<<inventario[indice].pc<<setw(10)<<inventario[indice].pv<<setw(13)<<inventario[indice].existencias<<setw(25)<<inventario[indice].nr<<"\n";
    }
    }
} 

void Modificaciones(){
    
    int opcion2;
    
    
    do{
        cout<<"Modificaciones\n";    
        cout<<"1. Precio de compra"<<endl;
        cout<<"2. Precio de Venta"<<endl;
        cout<<"3. Existencias"<<endl;
        cout<<"4. Nivel de reorden"<<endl;
        cout<<"5. Regresar al menu anterior"<<endl;
        cout<<"Opcion: ";
        cin>>opcion2;
        switch(opcion2){
            case 1: Precio_de_compra();
                break;
            case 2: Precio_de_venta();
                break;
            case 3: Existencias();
                break;
            case 4: Nivel_de_reorden();
                break;
            case 5: cout<<"Regresaste al menu de Administrador"<<endl;
                break;
            default:cout<<"Valor no valido.";
        };
    }while(opcion2!=5);
}

void Mostrar_inventario(){
    Resurtir();
    int i;
    
    cout<<"                              "<<"Mostrar Inventario"<<endl;
    cout<<left<<setw(8)<<"Id"<<setw(16)<<"Producto"<<setw(10)<<"PC"<<setw(10)<<"PV"<<setw(13)<<"Existencias"<<setw(25)<<"Nivel de reorden"<<setw(10)<<" "<<endl;
    for(i=0;i<Ntotal;i++)
        if(inventario[i].st==1)
           cout<<left<<setw(8)<<inventario[i].id<<setw(16)<<inventario[i].prod<<setw(10)<<inventario[i].pc<<setw(10)<<inventario[i].pv<<setw(13)<<inventario[i].existencias<<setw(25)<<inventario[i].nr<<resurtirA[i].resurtir<<"\n";
}

void Por_id(){ // esto me falta pasarlo a arreglo y hacer la burbuja
    
    int opcion1;
    
    do{
        cout<<"Menu Inventario"<<endl;
        cout<<"1. Menor a Mayor. "<<endl;
        cout<<"2. Mayor a Menor. "<<endl;
        cout<<"3. Salir. "<<endl;
        cout<<"Opcion: ";
        cin>>opcion1;
        switch(opcion1){
            case 1: Menor_a_mayor();
                break;                                                      
            case 2: Mayor_a_menor();
                break;
            case 3: cout<<" "<<endl;
                break;
            default:cout<<"Valor no valido.";
        };
    }while(opcion1!=3);    
}

void Menor_a_mayor(){ // esto me falta pasarlo a arreglo y hacer la burbuja
    
    int T,T4,T5,T6,i,j,opcion,inventario=5,index;
    float T1,T3;
    string T2;
    
    for(i=0;i<inventario;i++){
                for(j=0;j<inventario-1;j++){
                    if (id[j]>id[j+1]){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
                    T=id[j];
                    T1=pc[j];
                    T2=nombre[j];
                    T3=pv[j];
                    T4=existencias[j];
                    T5=nr[j];
                    id[j]=id[j+1];
                    pc[j]=pc[j+1];
                    nombre[j]=nombre[j+1];
                    pv[j]=pv[j+1];
                    existencias[j]=existencias[j+1];
                    nr[j]=nr[j+1];
                    id[j+1]=T;
                    pc[j+1]=T1;
                    nombre[j+1]=T2;
                    pv[j+1]=T3;
                    existencias[j+1]=T4;
                    nr[j+1]=T5;
                    }
                }    
    }

    cout<<"                              "<<"Mostrar Inventario"<<endl;
    cout<<left<<setw(8)<<"Id"<<setw(16)<<"Producto"<<setw(10)<<"PC"<<setw(10)<<"PV"<<setw(13)<<"Existencias"<<setw(25)<<"Nivel de reorden"<<setw(10)<<"Resurtir"<<endl;
    Resurtir();
    for(i=0;i<inventario;i++)
        if(st[i]==1)  
            cout<<left<<setw(8)<<id[i]<<setw(16)<<nombre[i]<<setw(10)<<pc[i]<<setw(10)<<pv[i]<<setw(13)<<existencias[i]<<setw(25)<<nr[i]<<resurtirC[i]<<"\n";
    
}

void Mayor_a_menor(){ // esto me falta pasarlo a arreglo y hacer la burbuja
    
    int T,T4,T5,T6,i,j,opcion,inventario=5,index;
    float T1,T3;
    string T2;
    
    for(i=0;i<inventario;i++){
            for(j=i+1;j<inventario;j++){
                if(id[i]<id[j]){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
                T=id[j];
                
                id[j]=id[i];
                
                id[i]=T;
                
                }
            }
        }
        cout<<"                              "<<"Mostrar Inventario"<<endl;
    cout<<left<<setw(8)<<"Id"<<setw(16)<<"Producto"<<setw(10)<<"PC"<<setw(10)<<"PV"<<setw(13)<<"Existencias"<<setw(25)<<"Nivel de reorden"<<setw(10)<<"Resurtir"<<endl;
    Resurtir();
    for(i=0;i<inventario;i++)
        if(st[i]==1)  
            cout<<left<<setw(8)<<id[i]<<setw(16)<<nombre[i]<<setw(10)<<pc[i]<<setw(10)<<pv[i]<<setw(13)<<existencias[i]<<setw(25)<<nr[i]<<resurtirC[i]<<"\n";
    
}

void Por_producto(){ // esto me falta pasarlo a arreglo y hacer la burbuja
 
    int i;
    
    
    cout<<"                              "<<"Mostrar Inventario"<<endl;
    cout<<left<<setw(8)<<"Id"<<setw(16)<<"Producto"<<setw(10)<<"PC"<<setw(10)<<"PV"<<setw(13)<<"Existencias"<<setw(25)<<"Nivel de reorden"<<setw(10)<<"Resurtir"<<endl;
    Resurtir();
    for(i=0;i<total;i++)
        if(st[i]==1)  
            cout<<left<<setw(8)<<id[i]<<setw(16)<<nombre[i]<<setw(10)<<pc[i]<<setw(10)<<pv[i]<<setw(13)<<existencias[i]<<setw(25)<<nr[i]<<resurtirC[i]<<"\n";
}

void Resurtir(){
    
    int i=0;
    string simbolo="*";
    
    for(i=0;i<total;i++)
        resurtirA[i].resurtir=(inventario[i].existencias<inventario[i].nr);
    resurtirA[i].resurtir=simbolo;
}
   
void Administracion_de_cuentas(){
    
    int opcion;
    
    cout<<"Administracion de Cuentas de Usuarios."<<endl;
    do{
        cout<<"Menu\n";    
        cout<<"1. Altas"<<endl;
        cout<<"2. Bajas"<<endl;
        cout<<"3. Consultas"<<endl;
        cout<<"4. Modificacion de contrase""\xa4""a"<<endl;
        cout<<"5. Mostrar cuentas de usuario"<<endl;
        cout<<"6. Regresar al menu anterior"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1: Altas_usuario();
                break;
            case 2: Bajas_de_usuario();
                break;
            case 3: Consulta_de_usuario();
                break;
            case 4: Modificaciones_de_contrasena();
                break;
            case 5: Mostrar_cuentas();
                break;
            case 6: cout<<" "<<endl;
                break;
            default:cout<<"Valor no valido."<<endl;
        };
    }while(opcion!=6);
}

void Corte_de_caja(){ // esto me falta pasarlo a arreglo
    
    double cortegeneral;
    
    cortegeneral=(cortedecajafinal+cortedecajafinal2);
    cout<<"Corte general: "<<cortegeneral<<endl;
}

int Buscar(string name){
    
    int i=0;
    
    while(inventario[i].prod!=name && i<Ntotal)
        i++;
    if(inventario[i].prod==name)
        return i;
    else
        return -1;
}   

void Altas_usuario(){
    
    int opcion;
    
    cout<<"Altas de cuentas"<<endl;
    do{
        cout<<"Menu\n";    
        cout<<"1. Administrador"<<endl;
        cout<<"2. Vendedor"<<endl;
        cout<<"3. Regresar al menu anterior"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1: Tpo1();
                break;
            case 2: Tpo2();
                break;
            case 3: cout<<"Regresaste al menu de Administrador"<<endl;
                break;
            default:cout<<"Valor no valido."<<endl;
        }
    }while(opcion!=3);
    ii++;
}

void Tpo1(){
    
    string nombre_temp;
    int i=ii,indice,contrasenaA;
    
    while(true){
        cout<<"Nombre: ";
        cin>>nombre_temp;
        indice=Buscar_cuentasA(nombre_temp);
        do{       
            lsA[indice].stuser=1;
            break;
        }while(lsA[indice].nombre==nombre_temp);
        if(nombre_temp=="*")
            break;
        if(indice==-1 || lsA[indice].stuser==0){            
            lsA[i].nombre=nombre_temp;
            cout<<"Contrase""\xa4""a: ";
            cin>>contrasenaA;
            lsA[i].contrasena=contrasenaA;
            lsA[i].stuser=1;
            lsA[i].tipo=1;
        }
        else
            cout<<"Registro ya existente"<<endl;
    }
    ii++;
}

void Tpo2(){
    
    string nombre_temp;
    int i=ii,indice,contrasenaA;
    
    while(true){
        cout<<"Nombre: ";
        cin>>nombre_temp;
        indice=Buscar_cuentasV(nombre_temp);
        do{       
            lsV[indice].stuser=1;
            break;
        }while(lsV[indice].nombre==nombre_temp);
        if(nombre_temp=="*")
            break;
        if(indice==-1 || lsV[indice].stuser==0){            
            lsV[i].nombre=nombre_temp;
            cout<<"Contrase""\xa4""a: ";
            cin>>contrasenaA;
            lsV[i].contrasena=contrasenaA;
            lsV[i].stuser=1;
            lsV[i].tipo=2;
        }
        else
            cout<<"Registro ya existente"<<endl;
    }
    ii++;
}
    
void Bajas_de_usuario(){ // esto me falta pasarlo a arreglo
     
    int encontrado,repetido;
    string nombre_temp;    
    
    while(true){
        cout<<"Nombre: ";
        cin>>nombre_temp;
        if(nombre_temp=="*")
            break;
        repetido=Buscar_cuentas(nombre_temp);
        if(stuser[repetido]!=0){    
            encontrado=Buscar_cuentas(nombre_temp);
            if(encontrado==-1 || stuser[encontrado]==0)
                 cout<<"No encontrado"<<endl;
            else{
                 stuser[encontrado]=0;      
                 cout<<"Usuario dado de baja"<<endl;        
            }  
        }
        else
            cout<<"Este usuario ya fue dado de baja"<<endl;
    }
}   

void Consulta_de_usuario(){ // esto me falta pasarlo a arreglo
    
    int indice;
    string nombre_temp;
    
    while(true){
    cout<<"Nombre: ";
    cin>>nombre_temp;
    if(nombre_temp=="*")
        break;
    indice=Buscar_cuentas(nombre_temp);
    if(indice==-1 || stuser[indice]==0)
        cout<<"No encontrado"<<endl;
     else{
        cout<<left<<setw(8)<<"Nombre"<<setw(16)<<"Contrase""\xa4""a"<<setw(10)<<"Tipo"<<endl;
        cout<<left<<setw(8)<<cuentas[indice]<<setw(16)<<contrasena[indice]<<tipo[indice]<<"\n";
    }
    }
}

void Modificaciones_de_contrasena(){ // esto me falta pasarlo a arreglo
     
    int indice,encontrado; 
    string nombre_temp;
    double precio_temp;
    
    while(true){
        cout<<"Nombre: ";
        cin>>nombre_temp;
        if(nombre_temp=="*")
            break;
        encontrado=Buscar_cuentas(nombre_temp);
        if(encontrado==-1 || stuser[encontrado]==0)
            cout<<"No encontrado"<<endl;
        else{
            cout<<"Nueva contrase""\xa4""a: ";
            cin>>precio_temp;    
            indice=Buscar_cuentas(nombre_temp);
            contrasena[indice]=precio_temp;
        }
    } 
     
}

void Mostrar_cuentas(){
     
    int i,iv;
    
    cout<<left<<setw(8)<<"Nombre"<<setw(16)<<"Contrase""\xa4""a"<<"Tipo"<<endl;
    for(i=0;i<total;i++)   
        if(lsA[i].stuser==1)
        cout<<left<<setw(8)<<lsA[i].nombre<<setw(16)<<lsA[i].contrasena<<lsA[i].tipo<<endl;
    for(iv=0;iv<total;iv++)
        if(lsV[iv].stuser==1)
        cout<<left<<setw(8)<<lsV[iv].nombre<<setw(16)<<lsV[iv].contrasena<<lsV[iv].tipo<<endl;
}

void Precio_de_compra(){
     
    int indice,encontrado; 
    string nombre_temp;
    double precio_temp;
    
    while(true){
        cout<<"Producto: ";
        cin>>nombre_temp;
        if(nombre_temp=="*")
            break;
        encontrado=Buscar(nombre_temp);
        if(encontrado==-1 || inventario[encontrado].st==0)
            cout<<"No encontrado"<<endl;
        else{
            cout<<"Nuevo precio: ";
            cin>>precio_temp;    
            indice=Buscar(nombre_temp);
            inventario[indice].pc=precio_temp;
        }
    }      
}

void Precio_de_venta(){
     
    int indice,encontrado; 
    string nombre_temp;
    double precio_temp;
    
    while(true){
        cout<<"Producto: ";
        cin>>nombre_temp;
        if(nombre_temp=="*")
            break;
        encontrado=Buscar(nombre_temp);
        if(encontrado==-1 || inventario[encontrado].st==0)
            cout<<"No encontrado"<<endl;
        else{
            cout<<"Nuevo precio: ";
            cin>>precio_temp;    
            indice=Buscar(nombre_temp);
            inventario[indice].pv=precio_temp;
        }
    }  
}

void Existencias(){
     
    int indice,encontrado; 
    string nombre_temp;
    double precio_temp;
    
    while(true){
        cout<<"Producto: ";
        cin>>nombre_temp;
        if(nombre_temp=="*")
            break;
        encontrado=Buscar(nombre_temp);
        if(encontrado==-1 || inventario[encontrado].st==0)
            cout<<"No encontrado"<<endl;
        else{
            cout<<"Existencias: ";
            cin>>precio_temp;    
            indice=Buscar(nombre_temp);
            inventario[indice].existencias=precio_temp;
        }
    }  
}

void Nivel_de_reorden(){
     
    int indice,encontrado; 
    string nombre_temp;
    double precio_temp;
    
    while(true){
        cout<<"Producto: ";
        cin>>nombre_temp;
        if(nombre_temp=="*")
            break;
        encontrado=Buscar(nombre_temp);
        if(encontrado==-1 || inventario[encontrado].st==0)
            cout<<"No encontrado"<<endl;
        else{
            cout<<"Nivel de reorden: ";
            cin>>precio_temp;    
            indice=Buscar(nombre_temp);
            inventario[indice].nr=precio_temp;
    
        }
    }  
}

void Autenticacion(){
    
    ListaAdmin();
    int indice,contrasenaA,contador=0;
    bool ingresa=false;
    string usuario;
    
    do{   
        cout<<"Usuario: ";
        cin>>usuario;
        cout<<"Contrase""\xa4""a: ";
        cin>>contrasenaA;
        indice=Buscar_cuentasA(usuario);
        if(indice!=-1 && lsA[indice].contrasena==contrasenaA && lsA[indice].tipo==1)
            ingresa=true;
        else{
            cout<<"Usuario o contrase""\xa4""a incorrectos"<<endl;
            contador++;
        }
    }while(ingresa==false && contador<3);
    if(ingresa==false){
        cout<<"Cerrando Sistema"<<endl;
        exit (EXIT_SUCCESS);
    }
}

int Buscar_cuentas(string name){
     
    int i=0;
    
    while(cuentas[i]!=name && i<totaluser)
        i++;
    if(cuentas[i]==name)
        return i;
    else
        return -1; 
}

int Buscar_cuentasA(string name){
     
    int i=0;
    
    while(lsA[i].nombre!=name && i<Ntotaluser)
        i++;
    if(lsA[i].nombre==name)
        return i;
    else
        return -1; 
}

int Buscar_cuentasV(string name){
     
    int i=0;
    
    while(lsV[i].nombre!=name && i<NtotaluserV)
        i++;
    if(lsV[i].nombre==name)
        return i;
    else
        return -1; 
}

void AutenticacionV(){
    
    ListaVend();
    int contrasenaA,contador=0;
    bool ingresa=false;
    string usuario;
    
    do{   
        cout<<"Usuario: ";
        cin>>nombreV_temp;
        cout<<"Contrase""\xa4""a: ";
        cin>>contrasenaA;
        indicecntventa=Buscar_cuentasV(nombreV_temp);
        if(indicecntventa!=-1 && lsV[indicecntventa].contrasena==contrasenaA && lsV[indicecntventa].tipo==2)
            ingresa=true;
        else{
            cout<<"Usuario o contrase""\xa4""a incorrectos"<<endl;
            contador++;
        }
    }while(ingresa==false && contador<3);
    if(ingresa==false){
         cout<<"Cerrando Sistema"<<endl;
         exit (EXIT_SUCCESS);
    }
 }
 
void Vendedor1(){ // esto me falta pasarlo a arreglo
     
    string nombre_temp;
    
    while(true){
        cout<<"Producto: ";
        cin>>nombre_temp;
        if(nombre_temp=="*"){
            Almacenamientocorte();
            Imprimir_ticket();
            Clientes2();
        }    
        if(nombre_temp=="**"){
            Cortedecaja1();
            break;
        }
        if(nombre_temp!="*"){
        encontradoV1=Buscar(nombre_temp);
        if(encontradoV1==-1 || st[encontradoV1]==0)
            cout<<"Sin existencias"<<endl;
        else{            
            Ventas_vendedor1();
            SubtotalV();
            Total();
        }
        }
    }
}

void Vendedor2(){ // esto me falta pasarlo a arreglo
     
    string nombre_temp;
    
    while(true){
        cout<<"Producto: ";
        cin>>nombre_temp;
        if(nombre_temp=="*"){
            Almacenamientocorte2();
            Imprimir_ticket2();
            Clientes2();
        }    
        if(nombre_temp=="**"){
            Cortedecaja2();
            break;
        }
        if(nombre_temp!="*"){
        encontradoV1=Buscar(nombre_temp);
        if(encontradoV1==-1 || st[encontradoV1]==0)
            cout<<"Sin existencias"<<endl;
        else{            
            Ventas_vendedor2();
            SubtotalVV2();
            Total2();
        }
        }
    }
}

void Ventas_vendedor1(){ // esto me falta pasarlo a arreglo
     
    int ventarealizada,i=encontradoV1;
    string yes;
             
    cout<<"Cantidad: ";
    cin>>precio_temp1;                   
    if(existencias[encontradoV1]<precio_temp1){       
        cout<<"No hay "<<precio_temp1<<" solo quedan "<<existencias[encontradoV1]<<endl;
        cout<<"Realizar la venta de "<<existencias[encontradoV1]<<"?"<<endl;
        cout<<"Y/N: ";
        cin>>yes;
        if(yes=="Y" || yes=="y"){
            ventarealizada=(existencias[encontradoV1]-precio_temp1);
            vendido=(precio_temp1+ventarealizada);         
            cantidadC1[i]=vendido;
            i++;
            sell[encontradoV1]=1;
            Actualizacion_inventario();
        }
    }
    else{
        Almacenamiento();
        Actualizacion_inventario();
    }
            
}  

void Ventas_vendedor2(){ // esto me falta pasarlo a arreglo
               
    int ventarealizada,vendido,i=encontradoV1;
    string yes;
    
    cout<<"Cantidad: ";
    cin>>precio_temp1;                   
    if(existencias[encontradoV1]<precio_temp1){       
        cout<<"No hay "<<precio_temp1<<" solo quedan "<<existencias[encontradoV1]<<endl;
        cout<<"Realizar la venta de "<<existencias[encontradoV1]<<"?"<<endl;
        cout<<"Y/N: ";
        cin>>yes;
        if(yes=="Y" || yes=="y"){
            ventarealizada=(existencias[encontradoV1]-precio_temp1);
            vendido=(precio_temp1+ventarealizada);         
            cantidadC1[i]=vendido;
            i++;
            sell[encontradoV1]=1;
            Actualizacion_inventario();
        }                       
    }
    else{
        Almacenamiento();
        Actualizacion_inventario();        
    }
            
}

void Actualizacion_inventario(){ // esto me falta pasarlo a arreglo
    
    venta1=(existencias[encontradoV1]-precio_temp1);
    if(venta1<0)
        venta1=0;
    existencias[encontradoV1]=venta1;
    sell[encontradoV1]=1;
}

void Almacenamiento(){ // esto me falta pasarlo a arreglo
    
    int i=encontradoV1;
        
    cantidadC1[i]=precio_temp1;
    i++;          
}

void Clientes2(){ // esto me falta pasarlo a arreglo
 
    int i=encontradoV1;
    
    for(i=0;i<total;i++){ 
        cantidadC1[i]=0;
        subtotal[i]=0;
        subtotal2[i]=0;
        totalV=0;
        totalV2=0;
        sell[i]=0;
    }
    i++;
    
}

void Cortedecaja1(){ // esto me falta pasarlo a arreglo
    
    int i=0;
    for(i=0;i<total;i++)  
        cortedecajafinal=(corte[i]+cortedecajafinal);
    i++;
    cout<<"Corte de caja: "<<cortedecajafinal<<endl;
}

void Almacenamientocorte(){ // esto me falta pasarlo a arreglo
    
    int j=ic;
    
    corte[j]=totalV;
    ic++;
}

void Imprimir_ticket(){ // esto me falta pasarlo a arreglo
    
    int i=0;    
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    
    cout<<"              "<<"Abarrotes \"La tiendita\""<<endl;
    cout<<"                "<<"RFC: LOLS840306GH9"<<endl;
    cout<<"                 "<<"Ticket de venta"<<endl;
    std::cout<<"                                     "<<"Hora:"<<std::put_time(&tm,"%H:%M:%S")<<std::endl;
    std::cout <<"                                  "<<"Fecha:"<<std::put_time(&tm, "%d/%m/%Y")<<std::endl;
    cout<<"Vendedor: "<<cuentas[indicecntventa]<<endl;
    cout<<left<<setw(12)<<"Producto"<<setw(10)<<"Cantidad"<<setw(20)<<"Pecio unitario"<<setw(25)<<"Subtotal"<<endl;
    for(i=0;i<total;i++)
        if(st[i]==1 && sell[i]==1)
        cout<<left<<setw(12)<<nombre[i]<<setw(10)<<cantidadC1[i]<<setw(20)<<pv[i]<<setw(25)<<subtotal[i]<<endl;   
        cout<<"                                    "<<"Total "<<totalV<<endl;
}

void Imprimir_ticket2(){ // esto me falta pasarlo a arreglo
    
    int i=0;    
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    
    cout<<"              "<<"Abarrotes \"La tiendita\""<<endl;
    cout<<"                "<<"RFC: LOLS840306GH9"<<endl;
    cout<<"                 "<<"Ticket de venta"<<endl;
    std::cout<<"                                     "<<"Hora:"<<std::put_time(&tm,"%H:%M:%S")<<std::endl;
    std::cout <<"                                  "<<"Fecha:"<<std::put_time(&tm, "%d/%m/%Y")<<std::endl;
    cout<<"Vendedor: "<<cuentas[indicecntventa]<<endl;
    cout<<left<<setw(12)<<"Producto"<<setw(10)<<"Cantidad"<<setw(20)<<"Pecio unitario"<<setw(25)<<"Subtotal"<<endl;
    for(i=0;i<total;i++)
        if(st[i]==1 && sell[i]==1)
        cout<<left<<setw(12)<<nombre[i]<<setw(10)<<cantidadC1[i]<<setw(20)<<pv[i]<<setw(25)<<subtotal2[i]<<endl;   
        cout<<"                                    "<<"Total "<<totalV2<<endl;
}

void SubtotalV(){ // esto me falta pasarlo a arreglo
    
    int i=encontradoV1;
    
    subtotalV1=(cantidadC1[i])*(pv[i]);
    subtotal[i]=subtotalV1;
    i++;
}

void SubtotalVV2(){ // esto me falta pasarlo a arreglo
    
    int i=encontradoV1;
    
    subtotalV2=(cantidadC1[i])*(pv[i]);
    subtotal2[i]=subtotalV2;
    i++;
}

void Total(){ // esto me falta pasarlo a arreglo
    
    
    totalV=(subtotalV1+totalV);
    
}

void Total2(){ // esto me falta pasarlo a arreglo
    
    
    totalV2=(subtotalV2+totalV2);
    
}

void Almacenamientocorte2(){ // esto me falta pasarlo a arreglo
    
    int k=ic2;
    
    corte2[k]=totalV2;
    ic2++;  
}

void Cortedecaja2(){ // esto me falta pasarlo a arreglo
    
    int i=0;
    
    for(i=0;i<total;i++)
        cortedecajafinal2=(corte2[i]+cortedecajafinal2);
    i++;
    cout<<"Corte de caja: "<<cortedecajafinal2<<endl;
}

int Buscar_id(int name){ // esto me falta pasarlo a arreglo
     
    int i=0,inventario=5;
    
    while(id[i]!=name && i<inventario)
        i++;
    if(id[i]==name)
        return i;
    else
        return -1; 
}

void Inicializacion(){
    
    inventario[0].id=2;
    inventario[0].prod="Leche";
    inventario[0].pc=12.35;
    inventario[0].pv=15.5;
    inventario[0].existencias=16;
    inventario[0].nr=5;
    inventario[0].st=1;
    inventario[1].id=4;
    inventario[1].prod="Pan";
    inventario[1].pc=5.5;
    inventario[1].pv=7.95;
    inventario[1].existencias=18;
    inventario[1].nr=6;
    inventario[1].st=1;
    inventario[2].id=1;
    inventario[2].prod="Agua";
    inventario[2].pc=13.39;
    inventario[2].pv=18.55;
    inventario[2].existencias=12;
    inventario[2].nr=4;
    inventario[2].st=1;
    inventario[3].id=3;
    inventario[3].prod="Huevos";
    inventario[3].pc=22.4;
    inventario[3].pv=30.39;
    inventario[3].existencias=20;
    inventario[3].nr=7;
    inventario[3].st=1;
    inventario[4].id=5;
    inventario[4].prod="Refresco";
    inventario[4].pc=10.99;
    inventario[4].pv=14.75;
    inventario[4].existencias=30;
    inventario[4].nr=8;
    inventario[4].st=1;
    inventario[5].id=6;
    inventario[5].prod="Aceite";
    inventario[5].pc=13.99;
    inventario[5].pv=25.75;
    inventario[5].existencias=25;
    inventario[5].nr=7;
    inventario[5].st=1;
    inventario[6].id=7;
    inventario[6].prod="Arroz";
    inventario[6].pc=20.6;
    inventario[6].pv=31.55;
    inventario[6].existencias=30;
    inventario[6].nr=8;
    inventario[6].st=1;
    Ntotal=7;
}

void ListaAdmin(){
    
    lsA[0].nombre="Mario";
    lsA[0].contrasena=123;
    lsA[0].stuser=1;
    lsA[0].tipo=1;
    lsA[1].nombre="Ramiro";
    lsA[1].contrasena=123;
    lsA[1].stuser=1;
    lsA[1].tipo=1;
    lsA[2].nombre="Sergio";
    lsA[2].contrasena=123;
    lsA[2].stuser=1;
    lsA[2].tipo=1;
    Ntotaluser=3;
}
    
void ListaVend(){
    
    lsV[0].nombre="Vend1";
    lsV[0].contrasena=123;
    lsV[0].stuser=1;
    lsV[0].tipo=2;
    lsV[1].nombre="Vend2";
    lsV[1].contrasena=123;
    lsV[1].stuser=1;
    lsV[1].tipo=2;
    NtotaluserV=2;
}



