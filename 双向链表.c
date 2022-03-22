#include <stdio.h>
#include <stdlib.h>

int ret; 
typedef struct Node
{
	
	int data;
	struct Node *prior;//ǰ�� 
	struct Node *next;//���� 
}List;
  
List *head;//����һ��ͷ��� 

/*List *Create_LinkList()//����һ�������� 
{

	head=(List *)malloc(sizeof(List));
	head->next=NULL;
	return head;
} */

void Creat_nNodeList(int n)//����һ����n������˫������
{
	    head=(List *)malloc(sizeof(List));
		int ret;
	    int i;
		List *temp; 
		List *s;
		temp=head;
		for(i=1;i<n+1;i++) 
		{
			s=(List *)malloc(sizeof(List));//�����ڴ�
			printf("�������%d����������:",i); 
			ret=scanf("%d",&s->data); 
			while(ret!=1)
	        {
	         	while(getchar()!='\n');
	         	printf("�������,��������\n");
	        	ret=scanf("%d",&s->data);
	        	
		    }//���Ƿ����� 
		    while(getchar()!='\n');
		    temp->next=s; 
		    s->prior=temp;
			temp=s; 
			
			//�����½��		  
		}
		temp->next=NULL; 
	    printf("�����������!\n");
			
} 

void ReadAllList() //��ȡ��ǰ���� 
{ 
     List *p; 
	 p=head->next; 
	while(p)
	{
		printf("%d->",p->data);
		p=p->next;
    }
    printf("NULL");
    printf("\n"); 
}

void InsertOneNode(int i,int data)//�ڵ�i�����ǰ�����½��,dataΪ���� 
{   
    int flag=1; 
	List *p;
	p=head;
	int j=1;
	while(j<i&&p)
	{
        p=p->next;
        ++j;
	}	
	if(!p||j>i)
	{
		printf("û�д˽��,����������\n");
		flag=0; 
	}
	if(flag==1) 
	{
	List *s; 
	//�½�� 
	s=(List *)malloc(sizeof(List)); 
	s->data=data;
	s->next=p->next;
	p->next=s; 
	
    }
    
}

int DeleteOneNode(int i)//ɾ����i����� 
{
	List *p;
	List *q; 
	
	int e; 
	p=head;
	int j=1;
	int flag=1; 
	while(j<i&&p->next)//�ҵ�Ҫɾ���Ľ�� 
	{
		
        p=p->next;
        ++j;
        
	}	
	if(!p->next||j>i)
	{
		printf("û�д˽��,����������\n");
		flag=0; 
	}
	if(flag) 
	{
		
	e=p->next->data; //ɾ���Ľ���ֵ 
    p->next->prior = p->prior;
	p->prior->next = p->next;
	
	free(p);
	
	return e;  
    }
    
}

void DeleteList()
{
	List *p;
	List *q;
	p=head->next;
	while(p)
	{
		q=p->next;
		free(p);
		p=q; 
	} 
	
	head->next=NULL; 
	
} 

void Menu()
{
 	printf("   **************  ϵͳ���ܲ˵�   **************     \n");
 	printf("   *  1.����������      **      2.�����½��         \n");
 	printf("   *  3.�������        **      4.ɾ�����          \n");
	printf("         **   5.ɾ�������˳�ϵͳ   **            \n");
	
}
int main()
{ 
	int i=1;
	int sign;//ѡ��Ҫ�Ĳ��� 
	int status=0;//�ж��Ƿ񽨺����� 
	while(1)
	{
	    Menu();
	    printf("\n��ѡ��Ҫ���еĲ���:"); 
	    ret=scanf("%d",&sign); 
	    while(ret!=1)
	    {
	    	while(getchar()!='\n');
	    	printf("�������,����������\n");
	    	Menu(); 
	    	ret=scanf("%d",&sign);
		}
		while(getchar()!='\n');//���Ƿ����� 
	    if(sign>5||sign<=0)
	    {
		printf("error!������һ��1-5������\n\n");
        } 
       else 
	   {
	      switch(sign)
	     {
	         case 1 : 
			 {
			   int n; 
			   printf("������Ҫ��������Ľ����:");
			   ret=scanf("%d",&n);
	           while(ret!=1)
	           {
	            	while(getchar()!='\n');
	    	        printf("�������,����������\n");
	             	ret=scanf("%d",&n);
			   }
			   while(getchar()!='\n');//���Ƿ�����
			   Creat_nNodeList(n);
			   status=1; 
			   break;
			    
		     }
	        case 2 : 
	         {
	            if(status==0)
		        {
		     	printf("����δ����,�޷����д˲���\n");	
				break; 
			    }	
			 int n; 
			 int data;
			 printf("������Ҫ���뵽�ĸ����ǰ:"); 
			 scanf("%d",&n);
			 while(ret!=1)
		     {
				         while(getchar()!='\n');
	    	             printf("�������,����������\n");
	                 	  ret=scanf("%d",&n); 
		     }//���Ƿ�����
			 printf("\nҪ���������:");
			 scanf("%d",&data);
			 while(ret!=1)
			 {
			          while(getchar()!='\n');
	    	             printf("�������,����������\n");
	                 	  ret=scanf("%d",&data); 
			 }
			 while(getchar()!='\n');//���Ƿ�����
			 printf("\n"); 
			 InsertOneNode(n,data);
			 break;
			 }    
	         case 3 : 
			  {
			  	if(status==0)
		        {
		     	printf("����δ����,�޷����д˲���\n");	
				break; 
			    }	
			    ReadAllList();
				break;
		      }
	        
	 		 case 4 : 
			  {     
			     if(status==0)
		        {
		     	printf("����δ����,�޷����д˲���\n");	
				break; 
			    }	
			       int n;
			  		printf("Ҫɾ���ĸ����:");
					scanf("%d",&n);
					while(ret!=1)
					{
							while(getchar()!='\n');
	    	                printf("�������,����������\n");
	                 	    ret=scanf("%d",&n); 
					}//���Ƿ�����
					printf("\n");
			        DeleteOneNode(n);
			        int e; 
			        e= DeleteOneNode(n);
			        printf("ɾ����ֵ��%d\n",e); 
			        break;
	         }  
	         case 5:
			 {
			 	if(status==0)
		        {
		     	printf("����δ����,�޷����д˲���\n");	
				break; 
			    }	
			 	DeleteList();
			 	break; 
			 } 
       }
       if(sign==5)
	     break; 
      }
    
	}
	return 0;
}

