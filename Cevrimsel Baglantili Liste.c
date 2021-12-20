#include <stdio.h> 
#include <stdlib.h> 

struct Node { 
			 int data; 
			 struct Node* next; 
			}; 
			
			
struct Node *ilk = NULL;   // ilk dugumu gosterecek pointer
struct Node *son = NULL;   // Son dugumu gosterecek pointer 
struct Node *adresi = NULL;
struct Node *birOncekininAdresi = NULL;



void ekle(int bilgi)
					{
						// Yapiyi isaret edecek pointer'i olustur
					   struct Node *ptr;
					   
					   // Bir Node yapisi kadar hafizada  yer ayir
					   ptr =(struct Node *)malloc(sizeof(struct Node));
					   
					   //data degiskenine bilgi degiskenini ata
					   ptr->data=bilgi;	
					   

					   				   
					   if(son==NULL)   // Liste bossa
								  {
										   ilk = ptr;  // ilk yapisinin adresini ilk isimli pointer'a ata
										   son = ptr;	
										   					
								  }
						else
								  {								  
		              				  son->next = ptr;  // bos degilse onceden eklenen Node yapisinin isaretini yeniyi gostercek sekilde ata
					   				  son = ptr;        // sonu gosteren pointer'i en son ekeleneni gosterecek sekilde ayarla
								  }
								  
								  ptr->next = ilk; //sonraki gosterdigi Node yapisinin adresini ilk eklenin degeri olarak ata
		
					   printf("\n\nListe:  ");                                // Ekleme isleminden sonra tekrar listele
                       listele(ilk);
		            }






void sil(int bilgi)
{
						              
						  if(ara(bilgi)== 0)   // silinmek istenen listede yoksa
						  {
			                          	printf(" Silinmesi istenilen %d listede yok", bilgi); 	
										return;		  	
						  }
 
                          else                // silinmek istenen listede ise
                          {
                                 adresiniBul(bilgi);
								 
								 if( adresi== ilk)   // silinmek istenen 1. eleman ise
                                {
		                                	if(ilk == son)             // ve listede tek eleman varsa
		                                	{
		                                		// listenin 1. elemani ve listede 1 eleman var
		                                		ilk = NULL;  
										        son = NULL;

											}
											else                    // listede birden fazla elaman varsa
											{
												ilk = adresi->next;
											}
								}
								else             // silinmek istenen 1. eleman disinda baska bir elemansa
								{
										adresiniBul(bilgi);
									    birOncekininAdresiniBul(bilgi);
									    birOncekininAdresi->next = adresi->next;									   	
										
										if(adresi == son) // silinmek istenen son elemansa
									       {
									       	    son = birOncekininAdresi;
									       	    birOncekininAdresi->next = ilk;
										   }

								}   
								
								  free(adresi);        // eleman silinip alan serbest birakilir
								  printf("\n\nSectiginiz eleman listeden silindi  ");
							      printf("\n\nListe:  ");                                // Silme isleminden sonra tekrar listele
                                  listele(ilk);
								                                  	

						  }

}




// Nesne listede kesin var. Adresi global adresi isimli pointer'a ataniyor
void adresiniBul(int bilgi) 
{ 
   struct Node *aranan = ilk;

     while(aranan != NULL)
	{  
        if(aranan->data == bilgi)                           
             { 
			     adresi = aranan;                     // Varsa adresi geri dondur
			     return 0;
		     }
			
		if(aranan->data != bilgi && aranan->next== NULL)
		   return 0;	
		
		if(aranan->next!= NULL)
		aranan = aranan->next;              //  isaretciyi bir sonrakine ata
		
 
    } 
    
}




void birOncekininAdresiniBul(int bilgi) 
{ 
   struct Node *aranan = ilk;
   
   
    while (aranan->next!= NULL) 
	{   
	    

		birOncekininAdresi = aranan;
		if(aranan->next!= NULL)
		        aranan = aranan->next;              //  isaretciyi NULL degilse bir sonrakine ata cunku silincek olan ilk eleman degil
		
		
		
	    if(aranan->data == bilgi)                           // Varsa adresi geri dondur
            {
            	adresi = aranan;  
			    return 0;
			}    
		
    } 

}





int ara(int bilgi) 
{ 
   struct Node *aranan = ilk;
   
     while(aranan != NULL)
	{  
        if(aranan->data == bilgi)                           
                return 1;
                
		if(aranan->next!= NULL)
		   aranan = aranan->next; 
		   
	    if(aranan->data != bilgi && aranan->next== NULL)
		   return 0;  
    } 
    
    return 0;
}






void listele(struct Node* n) 
{ 
   if(son == NULL)
   return;
   
   do
	{ 
        printf(" %d ", n->data);    // Tum elemanlari yazdir
        n = n->next;               // isaretciyi bir sonrakine ata
	} 
	 while (n != son);
	 
	 if(ilk != son)
	 printf(" %d ", son->data);
}





void ekranTemizle() 
				{
					system("cls");   
				}
 






int main() 
{ 
	int data,sec, sec1;
          char secim,secim1;
          ekranTemizle();
          
    	do 
          {
                   printf("\n________Tek Yonlu Bagli Liste Islemleri_________\n\n");
                   
                   printf("1.Ekle.\n");
                   printf("2.Sil.\n");
                   printf("3.Ara.\n");
                   printf("4.Listele.\n");
                   printf("5.Cik.\n");
                   printf("\nSeciminizi giriniz:");
                   
                   scanf("%d",&sec);
                   switch(sec)
                    {
                             case 1:  ekranTemizle();
							 		  printf("\nEklenecek dugum degerini giriniz  : ");
                                      scanf("%d",&data);
                                      ekle(data);
                                      break;
 
                             case 2: printf("\nSilinecek dugum degerini giriniz    :");
                                      scanf("%d",&data);
                                      sil(data);
                                      break;
                              
							case 3: printf("\nAranacak dugum degerini giriniz   :");
                                      scanf("%d",&data);
                                      if(ara(data)== 0)
                                      	printf(" %d listede yok", data);  
                                      else
                                        printf(" %d listede var", data);  
                                      break;          
                                      
 
                            case 4: ekranTemizle();
									printf("\n\nListe:  ");
                            		if(ilk != NULL)
                                      listele(ilk);
                                      break;
                            default: exit(0);
                   }
                   
                   fflush(stdin);
          }while(sec!=5);
	
	
	return 0; 
} 
