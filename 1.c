#include <stdio.h>
#include <stdlib.h>

int ret; 
typedef struct Node
{
	
	int data;
	struct Node *next;
	
}List;

List *head;//生成一个头结点 
 
/*List *Create_LinkList()//生成一个空链表 
{

	head=(List *)malloc(sizeof(List));
	head->next=NULL;
	return head;
} */

void Creat_nNodeList(int n)//创建一个有n个结点的链表
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
			temp=(List *)malloc(sizeof(List));//分配内存
			if(temp==NULL)
			printf("分配内存失败");
			 
			printf("请输入第%d个结点的数据:",i); 
			
			ret=scanf("%d",&temp->data); 
			while(ret!=1)
	        {
	         	while(getchar()!='\n');
	         	printf("输入错误,重新输入\n");
	        	ret=scanf("%d",&temp->data);
		    }//检测非法输入 
		
			temp1->next=temp;
			temp1=temp; 		  
		}
		temp1->next=NULL; 
	    printf("链表生成完成!\n");
			
} 

void ReadAllList() //读取当前链表 
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
	{List *s; //新结点 
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
	e=p->next->data; //删除结点的值 
	q=p->next;
	 
	p->next=q->next;
	free(q);
	return e;  
    }
}

void ListReverse() //反转链表  
{
	List *tem1=(List *)malloc(sizeof(List));
	List *tem2;
	List *tem3;//三个连续的指针 
	
	tem1=NULL;
	tem2=head; 
	
    while(tem2)
	{
		tem3=tem2->next;
		if((tem2->next=tem1)==head)
		tem2->next = NULL;//反转前两个结点 
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
        fast = fast->next->next;//走两格 
        slow = slow->next;//走一格 
        if(fast==slow) 
        {	
		    flag=0; 
            break; 
		}
		
    }
    if(flag==1)
	{
		printf("该链表未成环\n");
    } 
	else
	printf("该链表已成环\n"); 
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
	printf("此数据在表中出现了%d次\n",flag); 
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
 	printf("   **************  系统功能菜单   **************    \n");
 	printf("   *  1.创建新链表      **      2.插入新结点         \n");
 	printf("   *  3.输出链表        **      4.将链表反向            \n");
	printf("   *  5.找到链表中点    **      6.判断是否成环          \n");
 	printf("   *  7.删除结点        **      8.查询数据在表中有几个    \n");
 	printf("   *  9.构造循环链表    **      10.删除链表并退出系统   \n");
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
		}//检测非法输入 
	    if(sign>10||sign<=0)
	    {
		printf("error!请输入一个1-10的整数\n\n");
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
	              	Menu();
	             	ret=scanf("%d",&n);
			   }//检测非法输入
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
			    printf("该链表已成环,无法进行此操作\n");	break; 
		     } 
		     if(status==0)
		     {
		     	printf("链表未生成,无法进行此操作\n");	break; 
			 }
			   printf("请输入要插入到哪个结点前:"); 
			   scanf("%d",&n);
			 while(ret!=1)
		     {
				         while(getchar()!='\n');
	    	            printf("输入错误,请重新输入\n");
	              	      Menu();
	                 	  ret=scanf("%d",&n); 
		     }//检测非法输入
			 printf("\n要插入的数据:");
			 scanf("%d",&data);
			 while(ret!=1)
			 {
			          while(getchar()!='\n');
	    	             printf("输入错误,请重新输入\n");
	              	      Menu();
	                 	  ret=scanf("%d",&data); 
			}//检测非法输入
			 printf("\n"); 
			 InsertOneNode(n,data);
			 break;
			 }    
	         case 3 : 
			  {
				 if(i==0)
			    {
			    printf("该链表已成环,无法进行此操作\n");	break; 
		        } 
		        if(status==0)
		        {
		     	printf("链表未生成,无法进行此操作\n");	break; 
			    }
			    ReadAllList();
				break;
		      }
	         case 4 : 
			 {
			   if(i==0)
			 {
			    printf("该链表已成环,无法进行此操作\n");break;	
		     }
		       if(status==0)
		     {
		     	printf("链表未生成,无法进行此操作\n");	break; 
			 }
			 ListReverse();
			 break;
	 		 }
			  case 5 : 
			  {
			  if(status==0)
		     {
		     	printf("链表未生成,无法进行此操作\n");	break; 
			 }
			  if(i==0)
			 {
			    printf("该链表已成环,无法进行此操作\n");break;	
		     } 
			 FindMiddledata()  ;
			 printf("该链表的中间值是%d\n",FindMiddledata());
			 break;
			  } 
	          
	 		 case 6 : 
			  {
			    if(status==0)
		        {
		     	printf("链表未生成,无法进行此操作\n");	break; 
			    }
				i=JudgeCicle();
				break;
	       	  }
	 		 case 7 : 
			  {     
			      if(i==0)
			     {
			      printf("该链表已成环,无法进行此操作\n");break;	
		         } 
		         if(status==0)
		         {
		     	printf("链表未生成,无法进行此操作\n");	break; 
			     }
			  int n;
			  		printf("要删除哪个结点:");
			  		
					scanf("%d",&n);
					while(ret!=1)
					{
							while(getchar()!='\n');
	    	                printf("输入错误,请重新输入\n");
	              	        Menu();
	                 	    ret=scanf("%d",&n); 
					}//检测非法输入
					printf("\n");
			        DeleteOneNode(n);
			        break;
			  }
	 	 	 case 8 : 
			   {  
			     if(i==0)
			     {
			      printf("该链表已成环,无法进行此操作\n");break;	
		         } 
		         if(status==0)
		         {
		     	    printf("链表未生成,无法进行此操作\n");	break; 
			     }
			      int n;	
			   	  printf("请输入你要找的数据:");
			   	  scanf("%d",&n); 
			   	  while(ret!=1)
		          {
					 while(getchar()!='\n');
				     printf("输入错误,请重新输入\n");
	              	 Menu();
	             	 ret=scanf("%d",&n);
				  } //检测非法输入
			   	  printf("\n"); 
			      FindData(n);
			      break;
			   }
	 		 case 9 : 
			  {
			  	 if(i==0)
			     {
			      printf("该链表已成环,无法进行此操作\n");break;	
		         } 
			     CreatCircle();
			     i=JudgeCicle();
			     break;
		      }
	 		 case 10: 
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
	    if(sign==10) break;
       }
    }
	return 0;
}

