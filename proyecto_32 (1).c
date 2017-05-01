#include <conio.h>
#include <stdio.h>
#include <string.h>
#define n 1000
//se usa para crear el archivo
char arch_alm[]="inventario.csv"; 
//Se crea la estructura llamada laboratorio 
struct laboratorio{
	
	 char producto[30];
     char num_serie[30];
	 char descripcion[100];
     char cantidad[30];
     char marca[30];
     
     char ubicacion[30];
};

struct laboratorio  producto[n];
int indice=0;
//funciones y procedimientos
void ingresar(char p[30],char num[30],char descri[30],char canti[30],char mar[30],char unicacion[30]);
int producto_redes();
int producto_computo();
void insertar(char p[30],char num[30],char descri[30],char canti[30],char mar[30], char unicacion[30]);
void imprimir_producto();
void imprimir_producto_redes();
void imprimir_producto_computo();
void buscar_producto(char num[30]);
void eliminar_producto(char num[30]);
void editar_producto(char num[30]);
void almacenar();
void recuperar();
//Esta funcion sirve para almacenar los datos en el archivo 

void almacenar ()
{       
int j=0;
         
FILE *archivo;
archivo=fopen(arch_alm, "w+");    
for(j=0; j<indice; j++)
{
    fprintf(archivo, "%s %s %s %s %s %s\n \n", producto[j].producto,producto[j].num_serie,producto[j].descripcion,producto[j].marca,producto[j].cantidad,producto[j].ubicacion);
}
fclose(archivo);
}
//Esta funcion sirve para cambiar los datos de un producto
void editar_producto(char num[30])
{
	
	char p[30];
	int i=0,opcion1;

	while (i<indice && strcmp(num,producto[i].num_serie)!=0)
	{
	   i++;
	}
	 
	
	if (i>=indice)
	   printf("Producto no encontrado\n");
	else
	{
	 do{
//menu de la funcion editar 
	  printf("\n\n\t********EDICION**********\n\n");
      printf("\n\n1.-Cambiar producto\n");
      printf("\n\n2.-Cambiar num serie\n");
      printf("\n\n3.-Cambiar descripcion\n");
      printf("\n\n4.-Cambiar cantidad\n");
      printf("\n\n5.-Cambiar marca\n");
      printf("\n\n6.-Salir\n");
      printf("\n\nElige una opcion\n");
      scanf("%d",&opcion1);
      switch(opcion1)
      
      {
                     //casos para la funcion editar
      	case 1:
      		printf("\nNuevo producto:\n");
	        scanf("%s",p);
	        fflush(stdin);
	        strcpy(producto[i].producto,p);
	        break;
	        
	    case 2:
	        printf("\nNuevo numero de serie:\n");
	        scanf("%s",p);
	        fflush(stdin);
	         strcpy(producto[i].num_serie,p);
	        break;
	    case 3:
	    	printf("\nNueva descripcion:\n");
	        scanf("%s",p);
	        fflush(stdin);
	         strcpy(producto[i].descripcion,p);
	        break;
	    case 4:
	    	printf("\nNueva cantidad:\n");
	        scanf("%s",p);
	        fflush(stdin);
	         strcpy(producto[i].cantidad,p);
	        break;
	    case 5:
	    	printf("\nNueva marca:\n");
	        scanf("%s",p);
	        fflush(stdin);
	        strcpy(producto[i].marca,p);
	        break;
	        getch();
	        break;
	        
	        
	    }
	    
     }while(opcion1!=6);

	
	}
	
		
		
	
	
}
//Esta funcion nos permite recuperar los datos que se tienen en el inventario
void recuperar ()
{

char pr[30];
char num[30];
char des[100];
char cant[30];
char mar[30];
char ubi[30];
	    
FILE *archivo;
archivo=fopen(arch_alm, "r");
while(fscanf(archivo, "%s %s %s %s %s %s\n \n", pr,num,des,mar,cant,ubi)!=EOF)
{
    strcpy(producto[indice].producto,pr);
    strcpy(producto[indice].num_serie,num);
    strcpy(producto[indice].descripcion,des);  
    strcpy(producto[indice].marca,mar);
    strcpy(producto[indice].cantidad,cant);
    strcpy(producto[indice].ubicacion,ubi);
    indice++; 
}
      
       
}

//Esta funcion nos sirve para borrar un producto
void eliminar_producto(char num[30])
{   int k,i=0;
	while (i<indice && strcmp(num,producto[i].num_serie)!=0)
		   i++;
	
	if (i>=indice)  printf("Producto no encontrado\n");
	else{
	    for(k=i;k<indice-1;k++)
        {
        strcpy(producto[k].producto,producto[k+1].producto);
        strcpy(producto[k].num_serie,producto[k+1].num_serie);
        strcpy(producto[k].descripcion,producto[k+1].descripcion);
        strcpy(producto[k].cantidad,producto[k+1].cantidad);
        strcpy(producto[k].marca,producto[k+1].marca);
         strcpy(producto[k].ubicacion,producto[k+1].ubicacion);
        }
        printf("Producto eliminado\n");                        
    }
	indice --;
}	
//Busca un producto dentro del inventario 
void buscar_producto(char num[30])
{
	int i=0;

	while (i<indice && strcmp(num,producto[i].num_serie)!=0)
	{
	   i++;
	}
	 
	
	if (i>=indice)
	   printf("Producto no encontrado\n");
	else
		printf("Producto = %s\nnum_serie= %s\nDescripcion= %s\nCantidad= %s\nMarca= %s\nUbicacion= %s\n",producto[i].producto,producto[i].num_serie,producto[i].descripcion,producto[i].cantidad,producto[i].marca,producto[i].ubicacion);
}
//Nos permite agregar un producto al laboratorio de redes
void ingresar(char p[30],char num[30],char descri[30],char canti[30],char mar[30], char ubicacion[30])
{
if(producto_redes()==0)
     {
        strcpy(producto[indice].producto,p);
        strcpy(producto[indice].num_serie,num);
        strcpy(producto[indice].descripcion,descri);
        strcpy(producto[indice].cantidad,canti);
        strcpy(producto[indice].marca,mar);
        strcpy(producto[indice].ubicacion,ubicacion);
        indice++;	
    }
    
}
//Nos permite ingresar un producto para el laboratorio de computo
void insertar(char p[30],char num[30],char descri[30],char canti[30],char mar[30], char ubicacion[30])
{
if(producto_computo()==0)
     {  
        strcpy(producto[indice].producto,p);
        strcpy(producto[indice].num_serie,num);
        strcpy(producto[indice].descripcion,descri);
        strcpy(producto[indice].cantidad,canti);
        strcpy(producto[indice].marca,mar);
        strcpy(producto[indice].ubicacion,ubicacion);
        indice++;
    }
}
//Muestra los productos que se tienen registrados
void imprimir_producto()
{
int i;

for(i=0;i<indice;i++)
{
	printf("Producto = %s\nnum_serie= %s\nDescripcion= %s\nCantidad= %s\nMarca= %s\nUbicacion= %s\n",producto[i].producto,producto[i].num_serie,producto[i].descripcion,producto[i].cantidad,producto[i].marca,producto[i].ubicacion);
}	
}
//Muestra los productos del laboratorio de redes
void imprimir_producto_redes()
{
int i;

for(i=0;i<indice;i++)
{
	if (strcmp(producto[i].ubicacion,"Redes")==0)
	   printf("Producto = %s\nnum_serie= %s\nDescripcion= %s\nCantidad= %s\nMarca= %s\nUbicacion= %s\n",producto[i].producto,producto[i].num_serie,producto[i].descripcion,producto[i].cantidad,producto[i].marca,producto[i].ubicacion);
}	
}
//Muestra los productos del laboratorio de computo
void imprimir_producto_computo()
{
int i;

for(i=0;i<indice;i++)
{   if (strcmp(producto[i].ubicacion,"Computo")==0)
	printf("Producto = %s\nnum_serie= %s\nDescripcion= %s\nCantidad= %s\nMarca= %s\nUbicacion= %s\n",producto[i].producto,producto[i].num_serie,producto[i].descripcion,producto[i].cantidad,producto[i].marca,producto[i].ubicacion);
}	
}

int producto_redes()
{
	if(indice==n)
	     return 1;
	else 
	     return 0;
	
	
}
int producto_computo()
{
	if(indice==n)
	     return 1;
	else 
	     return 0;
	
	
}	
main()
{ 
      
     
     char p[30],num[30],descri[100],mar[30], canti[30];
      int opcion;
      
      // leer el nombre de administrador erick
      // leer la contraseña 
    char pass[20],passw[20];
printf("\n\nNombre de usuario\n"); 
 

     int x=1,i=0; 

     
      //Se piden caracteres hasta que se introduca enter 
     while(passw[x]!=13) 
     { 

          //Capturamos carácter 
         passw[x]=getch(); 
         
         //Si es un carácter válido y no se ha sobrepasado el límite de 20 caracteres se imprime un asterisco 
         if(passw[x]>32 && x<20) 
                 { 
                   putchar('*'); 
                   x++; 
                 } 
         //Si se pulsa la tecla RETROCESO, se retrocede un carácter, se imprime un espacio para eliminar el asterisco y se vuelve a retroceder para que el siguiente asterisco se coloque a continuación del anterior. 
         else if(passw[x]==8 && x>1) 
                 { 
                   putchar(8); 
                   putchar(' '); 
                   putchar(8); 
                   x--;  
                 } 
                     
     } 

     passw[x]='\0'; 
     
     
 printf("\n\nInserta la contrasena\n"); 
     
     
      //Se piden caracteres hasta que se introduca enter 
     while(pass[i]!=13) 
     { 

          //Capturamos carácter 
         pass[i]=getch(); 
         
         //Si es un carácter válido y no se ha sobrepasado el límite de 20 caracteres se imprime un asterisco 
         if(pass[i]>32 && i<20) 
                 { 
                   putchar('*'); 
                   i++; 
                 } 
         //Si se pulsa la tecla RETROCESO, se retrocede un carácter, se imprime un espacio para eliminar el asterisco y se vuelve a retroceder para que el siguiente asterisco se coloque a continuación del anterior. 
         else if(pass[i]==8 && i>0) 
                 { 
                   putchar(8); 
                   putchar(' '); 
                   putchar(8); 
                   i--;  
                 } 
                     
     } 

     pass[i]='\0'; 
     if(!strcmp(passw,"erick")==0 && strcmp(pass,"nirvana")==0)
     {
    
      //se incova al procedimiento recuperar que lee del archivo los datos
     recuperar(); 
     //Menu principal del inventario
     do{
     system("cls");
      printf("\n\n***************LABORATORIOS DE INGENIERIA***************\n\n");
      printf("\n\n1.-Laboratorio de redes");
      printf("\n\n2.-Laboratorio de computo");
      printf("\n\n3.-Mostrar todos los productos\n");
      printf("\n\n4.-Buscar por num. serie\n");
      printf("\n\n5.-Borrar producto por num. serie\n");
      printf("\n\n6.-Editar un producto por num. serie\n");
      printf("\n\n7.-Mostrar los productos de Lab. Redes\n");
      printf("\n\n8.-Mostrar los productos de Lab. Computo\n");
      printf("\n\n9.-Salir\n");
      printf("\n\nElige una opcion \n");
      scanf("%d",&opcion);
      switch(opcion)
	   //Casos del inventario
	      { 
       case 1: 
            printf("\nIngresa el producto:\n");
	        scanf("%s",p);
	        fflush(stdin);
	        printf("\nTeclea el numero de serie:\n");
	        scanf("%s",num);
	        fflush(stdin);
	        printf("Ingresa la descripcion: ");
	 scanf("%s",descri);
	        fflush(stdin);
	        
	        
	        printf("\nIngresa la cantidad:\n");
	        scanf("%s",canti);
	        printf("\nIngresa la marca:\n");
	        scanf("%s",mar);
	        ingresar(p,num,descri,canti,mar,"Redes");
	        break;
	    case 2:
            printf("\nTeclea el producto a ingresar:\n");
	        scanf("%s",p);
	        fflush(stdin);
	        printf("\nTeclea el numero de serie:\n");
	        scanf("%s",num);
	        fflush(stdin);
	        printf("\nIngresa la descripcion del producto:\n");
	        scanf("%s",descri);
	       
	        fflush(stdin);
	        printf("\nIngresa la cantidad:\n");
	        scanf("%s",canti);
	        printf("\nIngresa la marca:\n");
	        scanf("%s",mar);
	        insertar(p,num,descri,canti,mar,"Computo");
	        break;
	    case 3:
	        imprimir_producto();
	        getch();
	        break;
	     case 4:
	     	printf("\nTeclea el numero de serie:\n");
	        scanf("%s",num);
	        fflush(stdin);
	        buscar_producto(num);
	        getch();
	        break;
	        
	        case 5: 
            printf("\nTeclea el numero de serie:\n");
	        scanf("%s",num);
	        fflush(stdin);
            eliminar_producto(num);
	        getch();
	        break;
	        
	        case 6: 
             printf("\nTeclea el numero de serie:\n");
	        scanf("%s",num);
	        fflush(stdin);
	        editar_producto(num);	        
	        getch();
	        break;
	        
	      case 7:
	        imprimir_producto_redes();
	        getch();
	        break;
	      case 8:
	      	
	        imprimir_producto_computo();
	        getch();
	        break;
	        
	        case 9: 
            almacenar();
	     	break;
	        
	    }
	    
     }while(opcion!=9);
}

else 
         printf("\n\n\n\n\n\t\t*****ACCESO DENEGADO USUARIO O CONTRASENA INCORRECTA*****");
         system("pause > null"); 
 return 0; 
   
}

     
	        
	        
	        
      
     
     
