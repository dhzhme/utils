#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// ��̬�����ڴ�ռ�
#define MaxSize 50
typedef struct {
	// �洢����
	ElemType data[MaxSize];
	// ��¼��ǰ�Ѿ��洢�����ݸ���
	int length;
} SqList;

// ����Ԫ��, ������ɹ�����true, ��֮����false; L -> ������˳���; i -> ����Ԫ��Ŀ��λ��, 1 <= i <= length + 1; e -> �����Ԫ��
bool ListInsert(SqList& L, int i, ElemType e) {
	// �жϲ���λ���Ƿ�Ϸ�
	if (i < 1 || i > L.length + 1) {
		return false;
	}
	// �жϵ�ǰ˳����Ƿ�Ϊ����
	if (L.length >= MaxSize) {
		return false;
	}
	// ����Ԫ��
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	// ����Ԫ��
	L.data[i - 1] = e;
	// ����˳����е�Ԫ�ظ���
	L.length++;
	return true;
}
// ɾ��Ԫ��, ��ɾ���ɹ�����true, ��֮����false; L -> ������˳���; i -> ɾ��Ԫ��Ŀ��λ��, 1 <= i <= length; e -> ����ɾ����Ԫ�ظ�ֵ��e
bool ListDelete(SqList& L, int i, ElemType& e) {
	// �ж�ɾ��λ���Ƿ�Ϸ�
	if (i < 1 || i > L.length) {
		return false;
	}
	// �жϵ�ǰ˳����Ƿ�Ϊ�ձ�
	if (L.length <= 0) {
		return false;
	}
	// ��ȡiλ���ϵ�Ԫ��ֵ����ֵ��e
	e = L.data[i - 1];
	// ǰ��Ԫ��
	for (int j = i; j <= L.length - 1; j++) {
		L.data[j - 1] = L.data[j];
	}
	// ����˳����е�Ԫ�ظ���
	L.length--;
	return true;
}
// ����Ԫ��, �����ڸ���Ԫ���򷵻ظ�Ԫ�ص�λ��, ���򷵻�0; L -> ������˳���; e -> Ҫ���ҵ�Ԫ��
int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i + 1;
		}
	}
	return 0;
}
// ��ӡ˳���Ԫ��; L -> ������˳���
void PrintList(SqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%3d ", L.data[i]);
	}
	printf("\n");
}

int main() {
	SqList L; // ����һ��˳���
	bool ret; // ����һ����������ֵ
	ElemType del; // ����һ��ɾ����Ԫ��

	L.data[0] = 0; // ���Ԫ��
	L.data[1] = 1;
	L.data[2] = 2;
	L.length = 3; // ���õ�ǰlength��ֵ
	ret = ListInsert(L, 2, 60); // ��˳���L�ĵ�2��λ�ò���Ԫ��60
	if (ret) {
		PrintList(L); // �ڲ���ɹ����ӡ˳���
	}
	ret = ListDelete(L, 1, del); // ɾ��˳���L�ĵ�һ��Ԫ��, ������ֵ��ֵ��del
	if (ret) {
		PrintList(L); // ��ɾ���ɹ����ӡ˳���
		printf("%3d\n", del); // ��ӡ��ɾ����Ԫ�ص�ֵ
	}
	printf("%3d\n", LocateElem(L, 60)); // ��˳���L�в���Ԫ��60����ӡ��Ԫ�ص�λ��
	return 0;
}
