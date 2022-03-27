// ��ͷ���ĵ�����
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
// ���
typedef struct LNode {
	// ������
	ElemType data;
	// ָ����
	struct LNode* next;
} LNode, * LinkList;

// ͷ�巨�½�����, ���ش���������ͷָ��; L -> ͷָ��
LinkList CreateListHead(LinkList& L) {
	int value; // ����һ��������
	LinkList temp; // ����һ����ʱ�ṹ��ָ������ָ��һ���´����Ľ��

	// ����ͷ���
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	// ��ʼ��ȡ��һ������
	scanf_s("%d", &value);
	// �涨����������������9999���ʾ��������ʣ����������
	while (value != 9999) {
		// ����һ���½�����ڱ������������
		temp = (LinkList)malloc(sizeof(LNode));
		// ��ֵ������
		temp->data = value;
		// ��ֵָ����
		temp->next = L->next;
		// ��tempͷ��������
		L->next = temp;
		// ������ȡ����
		scanf_s("%d", &value);
	}
	return L;
}
// β�巨�½�����, ���ش���������ͷָ��; L -> ͷָ��
LinkList CreateListTail(LinkList& L) {
	int value; // ����һ��������
	LinkList temp; // ����һ����ʱ�ṹ��ָ������ָ��һ���´����Ľ��
	LinkList tail; // ����һ�����ָ������ָ������ĩβ

	// ����ͷ���
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	// ��tailָ��ͷ����ʾ��ʼ��
	tail = L;
	// ��ʼ��ȡ��һ������
	scanf_s("%d", &value);
	// �涨����������������9999���ʾ��������ʣ����������
	while (value != 9999) {
		// ����һ���½�����ڱ������������
		temp = (LinkList)malloc(sizeof(LNode));
		// ��ֵ������
		temp->data = value;
		// ��ֵָ����
		temp->next = NULL;
		// ��ĩβ�����½ڵ�
		tail->next = temp;
		// ����tail��ָ��
		tail = temp;
		// ������ȡ����
		scanf_s("%d", &value);
	}
	return L;
}
// ��λ����Ԫ��, �����ض���Ľṹ���ָ��; L -> ͷָ��; i -> Ҫ���ҵ�λ��
LinkList GetElem(LinkList L, int i) {
	int flag = 0; // ���ڱ�ǵ�ǰ��λ��, ��ֵΪ0��ʾ��ǰλ��λ��ͷ���

	// ����Ϊ0���ʾ����ͷָ��
	if (i == 0) {
		return L;
	}
	// ����Ϊ��ֵ���ʾ�Ƿ�ֱ�ӷ���NULL
	if (i < 1) {
		return NULL;
	}
	while (L && flag < i) {
		// ������
		L = L->next;
		// ���±��ֵ
		flag++;
	}
	// �����ض����ݽ��Ľṹ��ָ��
	return L;
}
// ��ֵ����Ԫ��, �����ض���Ľṹ���ָ��; L -> ͷָ��; i -> Ҫ���ҵ�Ԫ��ֵ
LinkList LocateElem(LinkList L, int e) {
	// ��ȡ��һ�����ݽ��
	L = L->next;
	// �����ж�ÿ�����ݽ�㱣���ֵ�Ƿ���ڸ���ֵe
	while (L != NULL) {
		// ����ǰ����ֵ���ڸ���ֵe�򷵻ص�ǰ��Ľṹ��ָ��
		if (L->data == e) {
			return L;
		}
		// �����ƶ�����һ��
		else {
			L = L->next;
		}
	}
	// ����ʧ���򷵻ص�ǰָ��ָ��, ��Ϊ��ʱ�˳���whileѭ��, ��˴�ʱLֵΪNULL
	return L;
}
// ����Ԫ��, ������ɹ�����true, ��֮����false; L -> �����������ͷָ��; i -> ����Ԫ��Ŀ��λ��; e -> �����Ԫ��
bool ListInsert(LinkList& L, int i, ElemType e) {
	// ��ȡ�ض�λ�õĽṹ��ָ��, ��ΪGetElem���ص���ĳһ���λ��, ����Ҫ�ڸ�λ�ò���һ������Ҫ���ǰһ��
	LinkList flag = GetElem(L, i - 1);
	// λ�÷Ƿ�, ����ʧ��
	if (flag == NULL) {
		return false;
	}
	// ����һ���½ڵ�
	LinkList temp = (LinkList)malloc(sizeof(LNode));
	// ��ֵ������
	temp->data = e;
	// ��ֵָ����
	temp->next = flag->next;
	// ���½ڵ���������
	flag->next = temp;
	return true;
}
// ɾ��Ԫ��, ��ɾ���ɹ�����true, ��֮����false; L -> �����������ͷָ��; i -> ɾ��Ԫ��Ŀ��λ��
bool ListDelete(LinkList& L, int i) {
	// ��ȡ�ض�λ�õ�ǰһ��, ��ΪGetElem���ص���ĳһ���λ��, ����Ҫɾ����λ�ý������Ҫ���ǰһ��
	LinkList temp = GetElem(L, i - 1);
	// ��ȡ�ض�λ����
	LinkList flag = temp->next;
	// λ�÷Ƿ�, ����ʧ��
	if (temp == NULL || flag == NULL) {
		return false;
	}
	// ɾ�����flag
	temp->next = flag->next;
	// �ͷ�flag���ڴ�ռ�
	free(flag);
	return true;
}
// ��ӡ����; L -> ͷָ��
void PrintList(LinkList L) {
	// ��ȡ��һ�����ݽ��
	L = L->next;
	while (L != NULL) {
		printf("%3d", L->data);
		L = L->next;
	}
	printf("\n");
}

int main() {
	LinkList L; // ͷָ��
	bool ret; // ����һ����������ֵ

	CreateListHead(L); // ͷ�巨��������
	PrintList(L); // ��ӡ����
	CreateListTail(L); // β�巨��������
	PrintList(L); // ��ӡ����
	printf("%3d\n", GetElem(L, 2)->data); // ��ӡ����L�ĵڶ������ݽ�㱣���ֵ
	if (LocateElem(L, 6) != NULL) {
		printf("%3d\n", LocateElem(L, 6)->data); // ��������L�Ƿ񱣴�������ֵ6, ���������ӡ��ֵ
	}
	ret = ListInsert(L, 3, 50); // ������L�ĵ�����λ�ò���Ԫ��100
	if (ret) {
		PrintList(L); // �ڲ���ɹ����ӡ����
	}
	ret = ListDelete(L, 1); // ɾ������L�ĵ�һ�����ݽ��
	if (ret) {
		PrintList(L); // ��ɾ���ɹ����ӡ����
	}
	return 0;
}
