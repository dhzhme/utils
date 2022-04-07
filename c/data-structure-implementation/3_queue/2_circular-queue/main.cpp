#include <stdio.h>

typedef int ElemType;

// ѭ������
#define MaxSize 5 // ѭ������ֻ�ܴ洢4��Ԫ��
typedef struct {
	// ���ݴ洢����
	ElemType data[MaxSize];
	// ָ����׵ı��
	int front;
	// ָ���β�ı��
	int rear;
} SqQueue;

// ��ʼ������; �޷���ֵ; Q -> �����ѭ������(����)
void InitQueue(SqQueue& Q) {
	// ��ʼ��ͷ��Ǻ�β���ͬʱָ�������һ��Ԫ��
	Q.front = Q.rear = 0;
}

// �пպ���; ����һ������ֵ, false ��ʾѭ�����в�Ϊ��, true ��ʾѭ������Ϊ��; Q -> �����ѭ������
bool isEmpty(SqQueue Q) {
	// ѭ�������пյ��߼���ͷ��ǵ���β���
	return Q.front == Q.rear;
}

// ��Ӻ���; ����һ������ֵ, false ��ʾ���ʧ��, true ��ʾ��ӳɹ�; Q -> �����ѭ������(����), e -> ���Ԫ��
bool EnQueue(SqQueue& Q, ElemType e) {
	// ѭ�������������߼��� ((rear + 1) % MaxSize) == front
	if ((Q.rear + 1) % MaxSize == Q.front) {
		return false; // ���ʧ��
	}
	// ���, ����Ԫ��
	Q.data[Q.rear] = e;
	// β��Ǻ���
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}

// ���Ӻ���; ����һ������ֵ, false ��ʾ����ʧ��, true ��ʾ���ӳɹ�; Q -> �����ѭ������(����), e -> ���Ӹ�ֵԪ��(����)
bool DeQueue(SqQueue& Q, ElemType& e) {
	if (isEmpty(Q)) {
		return false; // �ն��������ʧ��
	}
	// Ԫ�س���
	e = Q.data[Q.front];
	// ͷ��Ǻ���
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}

int main() {
	SqQueue Q; // ����ѭ������
	ElemType value; // �������

	// ��ʼ��ѭ������
	InitQueue(Q);
	// ѭ�������п�
	if (isEmpty(Q)) {
		printf("This circular queue is empty.\n");
	}
	// ���
	EnQueue(Q, 9);
	EnQueue(Q, 6);
	EnQueue(Q, 3);
	// ����
	for (int i = 0; i < 4; i++) {
		if (DeQueue(Q, value)) {
			printf("%d\n", value);
		}
		else {
			printf("This circular queue is empty.\n");
		}
	}
}
