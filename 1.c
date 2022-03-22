#include <stdio.h>
#include <stdlib.h>

int ret; 
typedef struct Node
{
	
	int data;
	struct Node *next;
	
}List;

List *head;//����һ��ͷ��� 
 
/*List *Create_LinkList()//����һ�������� 
{

	head=(List *)malloc(sizeof(List));
	head->next=NULL;
	return head;
} */

void Creat_nNodeList(int n)//����һ����n����������
{
		int ret;
	    int i;
	    head=(List *)malloc(sizeof(List));
		List *temp;
	    List *temp1;
	    temp=NULL; 
	    temp1=head; 
		
		for(i=1;i<n+1;i++) 
		{
			temp=(List *)malloc(sizeof(List));//�����ڴ�
			if(temp==NULL)
			printf("�����ڴ�ʧ��");
			 
			printf("�������%d����������:",i); 
			
			ret=scanf("%d",&temp->data); 
			while(ret!=1)
	        {
	         	while(getchar()!='\n');
	         	printf("�������,��������\n");
	        	ret=scanf("%d",&temp->data);
		    }//���Ƿ����� 
		
			temp1->next=temp;
			temp1=temp; 		  
		}
		temp1->next=NULL; 
	    printf("�����������!\n");
			
} 

void ReadAllList() //��ȡ��ǰ���� 
{ 
     List *p; 
	 p=head->next; 
	while(p!=NULL)
	{
		printf("%d->",p->data);
		p=p->next;
	
    }
    printf("NULL") ;
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
	{List *s; //�½�� 
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
	e=p->next->data; //ɾ������ֵ 
	q=p->next;
	 
	p->next=q->next;
	free(q);
	return e;  
    }
}

void ListReverse() //��ת����  
{
	List *tem1=(List *)malloc(sizeof(List));
	List *tem2;
	List *tem3;//����������ָ�� 
	
	tem1=NULL;
	tem2=head; 
	
    while(tem2)
	{
		tem3=tem2->next;
		if((tem2->next=tem1)==head)
		tem2->next = NULL;//��תǰ������� 
		tem1=tem2;
		tem2=tem3;
		
    }
	head->next=tem1;
}

int FindMiddledata()
{
	int e; 
	List *fast;
	List *slow;
	fast=head;
	slow=head; 
	while (fast&&fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    e=slow->data; 
}
int JudgeCicle()
{
	
	int flag=1; 
	List *fast;
	List *slow;
	fast=head;
	slow=head; 
	while (fast&&fast->next)
    {
        fast = fast->next->next;//������ 
        slow = slow->next;//��һ�� 
        if(fast==slow) 
        {	
		    flag=0; 
            break; 
		}
		
    }
    if(flag==1)
	{
		printf("������δ�ɻ�\n");
    } 
	else
	printf("�������ѳɻ�\n"); 
	return flag;
}

void CreatCircle()
{
	List *p=head ;
	while(1)
	{
		p=p->next;
		if(p->next==NULL)	
		{
			p->next=head; 
			break; 
		}
	}
} 
  
void FindData(int data)
{
	List *p;
	p=head;
	int flag=0; 
	while(p)
	{   
			if(p->data==data) 
			flag++;
		    p=p->next;
	 } 
	printf("�������ڱ��г�����%d��\n",flag); 
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
 	printf("   **************  ϵͳ���ܲ˵�   **************    \n");
 	printf("   *  1.����������      **      2.�����½��         \n");
 	printf("   *  3.�������        **      4.��������            \n");
	printf("   *  5.�ҵ������е�    **      6.�ж��Ƿ�ɻ�          \n");
 	printf("   *  7.ɾ�����        **      8.��ѯ�����ڱ����м���    \n");
 	printf("   *  9.����ѭ������    **      10.ɾ�������˳�ϵͳ   \n");
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
		}//���Ƿ����� 
	    if(sign>10||sign<=0)
	    {
		printf("error!������һ��1-10������\n\n");
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
	              	Menu();
	             	ret=scanf("%d",&n);
			   }//���Ƿ�����
			   Creat_nNodeList(n);
			   status=1; 
			   break;
		     }
	         case 2 : 
	         {
			 int n; 
			 int data;
		     if(i==0)
			 {
			    printf("�������ѳɻ�,�޷����д˲���\n");	break; 
		     } 
		     if(status==0)
		     {
		     	printf("����δ����,�޷����д˲���\n");	break; 
			 }
			   printf("������Ҫ���뵽�ĸ����ǰ:"); 
			   scanf("%d",&n);
			 while(ret!=1)
		     {
				         while(getchar()!='\n');
	    	            printf("�������,����������\n");
	              	      Menu();
	                 	  ret=scanf("%d",&n); 
		     }//���Ƿ�����
			 printf("\nҪ���������:");
			 scanf("%d",&data);
			 while(ret!=1)
			 {
			          while(getchar()!='\n');
	    	             printf("�������,����������\n");
	              	      Menu();
	                 	  ret=scanf("%d",&data); 
			}//���Ƿ�����
			 printf("\n"); 
			 InsertOneNode(n,data);
			 break;
			 }    
	         case 3 : 
			  {
				 if(i==0)
			    {
			    printf("�������ѳɻ�,�޷����д˲���\n");	break; 
		        } 
		        if(status==0)
		        {
		     	printf("����δ����,�޷����д˲���\n");	break; 
			    }
			    ReadAllList();
				break;
		      }
	         case 4 : 
			 {
			   if(i==0)
			 {
			    printf("�������ѳɻ�,�޷����д˲���\n");break;	
		     }
		       if(status==0)
		     {
		     	printf("����δ����,�޷����д˲���\n");	break; 
			 }
			 ListReverse();
			 break;
	 		 }
			  case 5 : 
			  {
			  if(status==0)
		     {
		     	printf("����δ����,�޷����д˲���\n");	break; 
			 }
			  if(i==0)
			 {
			    printf("�������ѳɻ�,�޷����д˲���\n");break;	
		     } 
			 FindMiddledata()  ;
			 printf("��������м�ֵ��%d\n",FindMiddledata());
			 break;
			  } 
	          
	 		 case 6 : 
			  {
			    if(status==0)
		        {
		     	printf("����δ����,�޷����д˲���\n");	break; 
			    }
				i=JudgeCicle();
				break;
	       	  }
	 		 case 7 : 
			  {     
			      if(i==0)
			     {
			      printf("�������ѳɻ�,�޷����д˲���\n");break;	
		         } 
		         if(status==0)
		         {
		     	printf("����δ����,�޷����д˲���\n");	break; 
			     }
			  int n;
			  		printf("Ҫɾ���ĸ����:");
			  		
					scanf("%d",&n);
					while(ret!=1)
					{
							while(getchar()!='\n');
	    	                printf("�������,����������\n");
	              	        Menu();
	                 	    ret=scanf("%d",&n); 
					}//���Ƿ�����
					printf("\n");
			        DeleteOneNode(n);
			        break;
			  }
	 	 	 case 8 : 
			   {  
			     if(i==0)
			     {
			      printf("�������ѳɻ�,�޷����д˲���\n");break;	
		         } 
		         if(status==0)
		         {
		     	    printf("����δ����,�޷����д˲���\n");	break; 
			     }
			      int n;	
			   	  printf("��������Ҫ�ҵ�����:");
			   	  scanf("%d",&n); 
			   	  while(ret!=1)
		          {
					 while(getchar()!='\n');
				     printf("�������,����������\n");
	              	 Menu();
	             	 ret=scanf("%d",&n);
				  } //���Ƿ�����
			   	  printf("\n"); 
			      FindData(n);
			      break;
			   }
	 		 case 9 : 
			  {
			  	 if(i==0)
			     {
			      printf("�������ѳɻ�,�޷����д˲���\n");break;	
		         } 
			     CreatCircle();
			     i=JudgeCicle();
			     break;
		      }
	 		 case 10: 
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
	    if(sign==10) break;
       }
    }
	return 0;
}

