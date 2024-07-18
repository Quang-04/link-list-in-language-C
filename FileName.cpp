#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// KHai bao 1 note co du kieu va con tro tro toi note co du lieu va dia chi
struct Node
{
	int data;
	Node* next;
};
typedef struct Node* node;
node makeNode(int x) {
	node tmp= new Node();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
bool empty(node a) {
	return a == NULL;
}
int size_of_node(node a) {
	int dem = 0;
	while (a != NULL) {
		a = a->next;
		dem++;
	}
	return dem;
}
void insertFirst(node &a,int x) {
	// Dau tien phai tao 1 node co data la x va co tro next
	node tmp = makeNode(x);
	if (a == NULL) {
		a = tmp;
	}
	else {
		tmp->next = a;
		// a no cx chi la ten , dia chi vung nho la node& (vd:0x1000)
		a = tmp;
	}
}
void insertLast(node &a,int x) {
	node tmp = makeNode(x);
	if (a == NULL) {
		a = tmp;
	}
	else {
		node p = a;//tai node dau co 2 ten a va p muon goi ten nao de ra node dau cx dc
		// Minh nhay dung nhung neu lm vay se khong lay lai dc du lieu Node o trc a hien tai nua vay mk se mat du lieu
		while (p->next != NULL) {
			p = p->next;
		}
		//Luc nay node cuoi co ten la p
		p->next = tmp;
		//a->next = tmp; neu lm vay thi a xog toi tmp lun se mat du lieu giua.
	}
}
// chen 1 node vao vi tri bat ky
void insert_select(node &a,int x,int select) {
	int n = size_of_node(a);
	node tmp = makeNode(x);
	if (select == 1) {
		insertFirst(tmp, x);// ham goi la truyen con tro ,ham viet la truyen dia chi o day tmp (node=Node*) la no da la con tro roi
		return;
	}
	else if (select == n) {
		insertLast(tmp, x);
		return;
	}
	else {
		node t = a;
		node s = a;
		for (int i = 1; i < select -1; i++) {
			t = t->next;
		}
		for (int u = 1; u < select ; u++) {
			s = s->next;
		}
		t->next = tmp;
		tmp->next = s;
	}
}
//Xoa note cuoi cung
void insert_delete_last(node& a) {
	int cac_note=size_of_node(a);
	if (a == NULL) {
		printf("\nChua co NODE nao trong data\n");
	}
	else {
		node e = a;
		for (int i = 1; i < (cac_note - 1); i++) {
			e = e->next;
		}
		e->next = NULL;
	}
}
void insert_select_delete(node &a,int select) {
	int n = size_of_node(a);
	if (a == NULL) {
		printf("\nChua co NODE nao trong data\n");
	}
	else if (select==1) {
		a = a->next;
	}
	else if (select==n) {
		insert_delete_last(a);
	}
	else {
		node node_f=a;
		node node_l=a;
		for (int i = 1; i <= (select - 2); i++) {
			node_f = node_f->next;
		}
		for (int u = 1; u <= (select-1); u++) {
			node_l = node_l->next;
		}
		node_f->next = node_l->next;

	}
}
void  search(node a,int x) {
	node tim_kiem=a;
	int n = size_of_node(a);
	for (int vi_tri = 1;vi_tri<=n; vi_tri++) {
		if (tim_kiem == NULL) {
			printf("\nGia tri khong hop le !!!\n");
			return ;
		}
		else if (tim_kiem->data == x) {
			printf("\nGia tri nam o vi tri thu %d", vi_tri);
			return;
		}
		else {
			tim_kiem = tim_kiem->next;
		}
	}
}
void search_last(node a) {
	node sau = a;
	while (sau->next!=NULL) {
		sau=sau->next;
	}
	printf("\nGia tri cua node o vi tri cuoi cung la %d", sau->data);
}
void search_index(node a,int vi_tri) {
	int n = size_of_node(a);
	if (vi_tri<0 || vi_tri>n) {
		printf("\nLoi: qua gioi han data");
		return;
	}
	else {
		node tmp=a;
		int dem = 1;
		do {
			if (dem == vi_tri) {
				printf("\nGia tri node tai vi tri %d la %d", vi_tri, tmp->data);
			}
			dem++;
			tmp = tmp->next;
		} while (dem<=vi_tri);
	}
}
void delete_all(node& a) {
	a = NULL;
}
void Indata(node a) {
	int n = size_of_node(a);
	for (int i=1;i<=n; i++) {
		printf("| %d |  ",a->data);
		a=a->next;
	}
}
int main() {
	node head = NULL;
	int x; int chon;
	do {
		printf("\n1:Tao node dau.");
		printf("\n2:Tao node cuoi.");
		printf("\n3:Tao node lua chon.");
		printf("\n4:Xoa data cuoi:");
		printf("\n5:Xoa data vi tri tuy chon:");
		printf("\n6:In data.");
		printf("\n7:Tim vi tri cua 1 node theo gia tri.");
		printf("\n8:Lay gia tri o vi tri node cuoi cung.");
		printf("\n9:Lay gia tri o node bat ky.");
		printf("\n0:HUY");
		printf("\nLua chon:"); scanf("%d", &chon);
		if (chon == 1) {
			printf("\nNhap data muon chen vao dau hang:"); scanf("%d",&x);
			insertFirst(head, x);
		}
		else if (chon == 2) {
			printf("\nNhap data muon chen vao cuoi hang:"); scanf("%d",&x);
			insertLast(head, x);
		}
		else if (chon == 3) {
			int vi_tri;
			printf("\nNhap data muon chen:"); scanf("%d", &x);
			printf("\nNhap vi tri muon chen:"); scanf("%d", &vi_tri);
			insert_select(head, x, vi_tri);
		}
		else if (chon == 4) {
			insert_delete_last(head);
		}
		else if(chon == 5) {
			int vi_tri;
			printf("\nChon vi tri muon xoa:"); scanf("%d", &vi_tri);
			insert_select_delete(head,vi_tri);
		}
		else if (chon == 6) {
			printf("\nIn data:"); Indata(head);

		}
		else if (chon == 7) {
			int tim_kiem;
			printf("\nNhap gia tri muon tim:"); scanf("%d", &tim_kiem);
			search(head,tim_kiem);
		}
		else if (chon == 8) {
			search_last(head);
		}
		else if (chon == 9) {
			int vi_tri;
			printf("\nNhap vi tri muon xem gia tri:"); scanf("%d", &vi_tri);
			search_index(head,vi_tri);
		}
		printf("\n-----------------------------------------------");
	} while (chon != 0);
}
