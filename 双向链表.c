#include <stdio.h>
#include <stdlib.h>

int ret; 
typedef struct Node
{
	
	int data;
	struct Node *prior;//前驱 
	struct Node *next;//后驱 
}List;
  
List *head;//生成一个头结点 

/*List *Create_LinkList()//生成一个空链表 
{

	head=(List *)malloc(sizeof(List));
	head->next=NULL;
	return head;
} */

void Creat_nNodeList(int n)//创建一个有n个结点的双向链表
{
	    head=(List *)malloc(sizeof(List));
		int ret;
	    int i;
		List *temp; 
		List *s;
		temp=head;
		for(i=1;i<n+1;i++) 
		{
			s=(List *)malloc(sizeof(List));//分配内存
			printf("请输入第%d个结点的数据:",i); 
			ret=scanf("%d",&s->data); 
			while(ret!=1)
	        {
	         	while(getchar()!='\n');
	         	printf("输入错误,重新输入\n");
	        	ret=scanf("%d",&s->data);
	        	
		    }//检测非法输入 
		    while(getchar()!='\n');
		    temp->next=s; 
		    s->prior=temp;
			temp=s; 
			
			//生成新结点		  
		}
		temp->next=NULL; 
	    printf("链表生成完成!\n");
			
} 

void ReadAllList() //读取当前链表 
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

void InsertOneNode(int i,int data)//在第i个结点前插入新结点,data为数据 
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
		printf("没有此结点,请重新输入\n");
		flag=0; 
	}
	if(flag==1) 
	{
	List *s; 
	//新结点 
	s=(List *)malloc(sizeof(List)); 
	s->data=data;
	s->next=p->next;
	p->next=s; 
	
    }
    
}

int DeleteOneNode(int i)//删除第i个结点 
{
	List *p;
	List *q; 
	
	int e; 
	p=head;
	int j=1;
	int flag=1; 
	while(j<i&&p->next)//找到要删除的结点 
	{
		
        p=p->next;
        ++j;
        
	}	
	if(!p->next||j>i)
	{
		printf("没有此结点,请重新输入\n");
		flag=0; 
	}
	if(flag) 
	{
		
	e=p->next->data; //删除的结点的值 
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
 	printf("   **************  系统功能菜单   **************     \n");
 	printf("   *  1.创建新链表      **      2.插入新结点         \n");
 	printf("   *  3.输出链表        **      4.删除结点          \n");
	printf("         **   5.删除链表并退出系统   **            \n");
	
}
int main()
{ 
	int i=1;
	int sign;//选择要的操作 
	int status=0;//判断是否建好链表 
	while(1)
	{
	    Menu();
	    printf("\n请选择要进行的操作:"); 
	    ret=scanf("%d",&sign); 
	    while(ret!=1)
	    {
	    	while(getchar()!='\n');
	    	printf("输入错误,请重新输入\n");
	    	Menu(); 
	    	ret=scanf("%d",&sign);
		}
		while(getchar()!='\n');//检测非法输入 
	    if(sign>5||sign<=0)
	    {
		printf("error!请输入一个1-5的整数\n\n");
        } 
       else 
	   {
	      switch(sign)
	     {
	         case 1 : 
			 {
			   int n; 
			   printf("请输入要创建链表的结点数:");
			   ret=scanf("%d",&n);
	           while(ret!=1)
	           {
	            	while(getchar()!='\n');
	    	        printf("输入错误,请重新输入\n");
	             	ret=scanf("%d",&n);
			   }
			   while(getchar()!='\n');//检测非法输入
			   Creat_nNodeList(n);
			   status=1; 
			   break;
			    
		     }
	        case 2 : 
	         {
	            if(status==0)
		        {
		     	printf("链表未生成,无法进行此操作\n");	
				break; 
			    }	
			 int n; 
			 int data;
			 printf("请输入要插入到哪个结点前:"); 
			 scanf("%d",&n);
			 while(ret!=1)
		     {
				         while(getchar()!='\n');
	    	             printf("输入错误,请重新输入\n");
	                 	  ret=scanf("%d",&n); 
		     }//检测非法输入
			 printf("\n要插入的数据:");
			 scanf("%d",&data);
			 while(ret!=1)
			 {
			          while(getchar()!='\n');
	    	             printf("输入错误,请重新输入\n");
	                 	  ret=scanf("%d",&data); 
			 }
			 while(getchar()!='\n');//检测非法输入
			 printf("\n"); 
			 InsertOneNode(n,data);
			 break;
			 }    
	         case 3 : 
			  {
			  	if(status==0)
		        {
		     	printf("链表未生成,无法进行此操作\n");	
				break; 
			    }	
			    ReadAllList();
				break;
		      }
	        
	 		 case 4 : 
			  {     
			     if(status==0)
		        {
		     	printf("链表未生成,无法进行此操作\n");	
				break; 
			    }	
			       int n;
			  		printf("要删除哪个结点:");
					scanf("%d",&n);
					while(ret!=1)
					{
							while(getchar()!='\n');
	    	                printf("输入错误,请重新输入\n");
	                 	    ret=scanf("%d",&n); 
					}//检测非法输入
					printf("\n");
			        DeleteOneNode(n);
			        int e; 
			        e= DeleteOneNode(n);
			        printf("删除的值是%d\n",e); 
			        break;
	         }  
	         case 5:
			 {
			 	if(status==0)
		        {
		     	printf("链表未生成,无法进行此操作\n");	
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

