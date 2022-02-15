#include <stdio.h>
#include <time.h>

const int m=24, n=60;
const char nave=2, encontrar=3, pared=177;

void imprimir(int a[m][n]);

int main(void){
	int a[m][n];
	
	int i,j,k,z, ale;
	
	//DISEÑO DEL MAPA
	srand(time(NULL));
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			ale=rand()%100+5;
			if(ale%2==0){
				a[i][j]=' ';
			}
			else{
				z=0;
				for(k=3;k<ale;k++){
					if(ale%k==0){
						z++;
					}
				}
				if(z==0){
					a[i][j]=pared;
				}
				else{
					a[i][j]=' ';
				}
			}
		}
	}
	
	
	//COLOCANDO LA NAVE
	z=1;
	j=n/2;
	while(z){
		if(a[0][j]!=pared){
			a[0][j]=nave;
			z=0;
		}
		else{
			j++;
		}
	}
	
	//Colocando el objeto
	z=1;
	j=n/2;
	
	ale=rand()%2+1;
	while(z){
		if(ale%2==0) j=n-1;
		else j=0;
		
		if(a[m-1][j]!=pared){
				a[m-1][j]=encontrar;
				z=0;
			}
		else{
			if(ale%2==0) j++;
			else j--;
		}
	}
	
	
	
	//JUEGO----------------------------------------------
	printf("VERSION SAN VALENTIN\n\n\tEncuentra el coraz%cn para ganar!!!\n\n",162);
	system("pause");
	
	z=1;
	do{
		system("cls");
		imprimir(a);
		printf("\n             w\ncontroles: a s d\t");
		k=getch();
		
		//CONTROLES
		if(k=='w'){
			for(i=0;i<m;i++){
				for(j=0;j<n;j++){
					if(a[i][j]==nave){
						a[i][j]=' ';
						if(a[i-1][j]==pared){
							z=0;
						}
						else if(a[i-1][j]==encontrar){
							z=0;
							printf("JAJAJA te la creiste?");
							getch();
						}
						a[i-1][j]=nave;
						a[i][j]==' ';
					}
				}
			}
		}
		if(k=='a'){
			for(i=0;i<m;i++){
				for(j=0;j<n;j++){
					if(a[i][j]==nave){
						a[i][j]=' ';
						if(a[i][j-1]==pared){
							z=0;
						}
						else if(a[i][j-1]==encontrar){
							z=0;
							printf("JAJAJA te la creiste?");
							getch();
						}
						a[i][j-1]=nave;
						a[i][j]==' ';
					}
				}
			}
		}
		if(k=='s'){
			for(i=m-1;i>=0;i--){
				for(j=n-1;j>=0;j--){
					if(a[i][j]==nave){
						a[i][j]=' ';
						if(a[i+1][j]==pared){
							z=0;
						}
						else if(a[i+1][j]==encontrar){
							z=0;
							printf("JAJAJA te la creiste?");
							getch();
						}
						a[i+1][j]=nave;
						a[i][j]==' ';
					}
				}
			}
		}
		if(k=='d'){
			for(i=m-1;i>=0;i--){
				for(j=n-1;j>=0;j--){
					if(a[i][j]==nave){
						a[i][j]=' ';
						if(a[i][j+1]==pared){
							z=0;
						}
						else if(a[i][j+1]==encontrar){
							z=0;
							printf("JAJAJA te la creiste?");
							getch();
						}
						a[i][j+1]=nave;
						a[i][j]==' ';
					}
				}
			}
		}
		
		//VERIFICACION 
		ale=0;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(a[i][j]!=nave){
					ale++;
				}
			}
		}
		if(ale==m*n){
			z=0;
		}
	}while(z);
	
	system("cls");
	imprimir(a);	getch();
	printf("\n\t...PERDISTE pipipi...");
	return 0;
}


void imprimir(int a[m][n]){
	int i,j;
	
	for(j=0;j<n;j++){
			if(j==0) printf(" ");
			printf("-");
			if(j==n-1) printf("\n");
		}
		
	for(i=0;i<m;i++){
		printf("|");
		for(j=0;j<n;j++){
			printf("%c",a[i][j]);
		}
		printf("|\n");
	}
	
	for(j=0;j<n;j++){
			if(j==0) printf(" ");
			printf("-");
		}
}
