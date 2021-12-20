#include <stdio.h> 
#include <stdlib.h> 

struct Node { 
			 int data; 
			 struct Node* next; 
			 struct Node* prev;
			}; 
			
			
struct Node *ilk = NULL;   // ilk dugumu gosterecek pointer
struct Node *son = NULL;   // Son dugumu gosterecek pointer 
struct Node *adresi = NULL;


void ekle(int bilgi)
					{
						// Yapiyi isaret edecek pointer'i olustur
					   struct Node *ptr;
					   
					   // Bir Node yapisi kadar hafizada  yer ayir
					   ptr =(struct Node *)malloc(sizeof(struct Node));
					   
					   //data degiskenine bilgi degiskenini ata
					   ptr->data=bilgi;	
					   
					   //sonraki gosterdigi Node yapisinin adresini bos yap
					   ptr->next = NULL;
					   				   
					   if(son==NULL)   // Liste bossa
								  {
										   ilk = ptr;  // ilk yapisinin adresini ilk isimli pointer'a ata
										   son = ptr;
										   ptr->next = NULL;
										   ptr->prev = NULL;	 
								  }
						else
								  {								  
		              				  son->next = ptr;  // bos degilse onceden eklenen Node yapisinin isaretini yeniyi gostercek sekilde ata
		              				  ptr->prev	= son;  // ve eklenen Node yapisinin bir oncekini gosterecek sekilde ata
					   				  son = ptr;        // sonu gosteren pointer'i en son ekeleneni gosterecek sekilde ayarla
								  }
		
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
												(adresi->next)->prev = NULL;
											}
								}
								else             // silinmek istenen 1. eleman disinda baska bir elemansa
								{
										adresiniBul(bilgi);
									    (adresi->prev)->next = adresi->next;	// bir oncekinin adresini bul ve next degerine silinecek olanin next degerini ata								   	
										
										if(adresi == son) // silinmek istenen son elemansa
									       {
									       	    son = adresi->prev;
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
    while (n != NULL) 
	{ 
        printf(" %d ", n->data);    // Tum elemanlari yazdir
        n = n->next;               // isaretciyi bir sonrakine ata
    } 
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
