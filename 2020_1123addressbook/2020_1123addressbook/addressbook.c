//ͨѶ¼
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define PERSON_MAX 1000

typedef struct Person{
	char name[1024];
	char sex[1024];
	int age;
	char telephone[1024];
	char address[1024];
}Person;

typedef struct AddressBook{
	Person person[PERSON_MAX];
	//ͨѶ¼����Ч����ϵ�˸���
	int size;
}AddressBook;
void initAddressBook(AddressBook* addressbook){
	addressbook->size = 0;
}
void addPerson(AddressBook* addressbook){
	printf("�����ϵ��\n");
	if (addressbook->size >= PERSON_MAX){
		printf("ͨѶ¼����,���ʧ��\n");
		return;
	}
	Person* person=&addressbook->person[addressbook->size];
	printf("��������ϵ�˵�����\n");
	scanf("%s", person->name);
	printf("��������ϵ�˵��Ա�\n");
	scanf("%s", person->sex);
	printf("��������ϵ�˵�����\n");
	scanf("%d", &person->age);
	printf("��������ϵ�˵ĵ绰\n");
	scanf("%s", person->telephone);
	printf("��������ϵ�˵ĵ�ַ\n");
	scanf("%s", person->address);

	addressbook->size++;
	printf("�����ϵ�˳ɹ�\n");
	return;
}
void delPerson(AddressBook* addressbook){
	printf("������Ҫɾ������ϵ�˵����:");
	int number = 0;
	scanf("%d", &number);
	if (number < 0 || number >= addressbook->size){
		printf("�����ڸ���ŵ���ϵ��\n");
		return;
	}
	printf("ȷ��ɾ��[%d]����ϵ����? (y/n):",number);
	char choice[1024] = "n";
	scanf("%s", choice);
	if (strcmp(choice, "y") || strcmp(choice, "yes")){
		addressbook->person[number] = addressbook->person[addressbook->size-1];
		addressbook->size--;
		printf("����ϵ����ɾ��\n");
	}
	return;
}
void findPerson(AddressBook* addressbook){
	printf("������Ҫ���ҵ���ϵ�˵����:");
	int number = 0;
	scanf("%d", &number);
	if (number < 0 || number >= addressbook->size){
		printf("�����ڸ���ŵ���ϵ��\n");
		return;
	}

	printf("���\t����\t\t�Ա�\t����\t�绰\t\t��ַ\n");
		printf("[%d]\t%s\t\t%s\t%d\t%s\t%s\n", number,
			addressbook->person[number].name,
			addressbook->person[number].sex, addressbook->person[number].age,
			addressbook->person[number].telephone, addressbook->person[number].address
			);
}
void alterPerson(AddressBook* addressbook){
	printf("������Ҫ�޸ĵ���ϵ�˵����:");
	int number = 0;
	scanf("%d", &number);
	if (number < 0 || number >= addressbook->size){
		printf("�����ڸ���ŵ���ϵ��\n");
		return;
	}

	Person* person = &addressbook->person[number];
	printf("��������ϵ�˵�����\n");
	scanf("%s", person->name);
	printf("��������ϵ�˵��Ա�\n");
	scanf("%s", person->sex);
	printf("��������ϵ�˵�����\n");
	scanf("%d", &person->age);
	printf("��������ϵ�˵ĵ绰\n");
	scanf("%s", person->telephone);
	printf("��������ϵ�˵ĵ�ַ\n");
	scanf("%s", person->address);

	printf("�޸���ϵ�˳ɹ�\n");
	return;
}
void showPerson(AddressBook* addressbook){
	if (addressbook->size == 0){
		printf("��ǰͨѶ¼Ϊ��\n");
		return;
	}
	printf("���\t����\t\t�Ա�\t����\t�绰\t\t��ַ\n");
	for (int i = 0; i < addressbook->size; i++){
		printf("[%d]\t%s\t\t%s\t%d\t%s\t%s\n", i,
			addressbook->person[i].name,
			addressbook->person[i].sex, addressbook->person[i].age,
			addressbook->person[i].telephone, addressbook->person[i].address
			);
	}
	printf("��ͨѶ¼��[%d]����ϵ��\n", addressbook->size);
	return;
}

void clearPerson(AddressBook* addressbook){
	printf("ȷ�������? (y/n) :");
	char choice[1024]="no";
	scanf("%s", choice);
	if (strcmp(choice ,"y")==0||strcmp(choice,"yes")==0){
		addressbook->size = 0;
		printf("ͨѶ¼�����\n");
	}
	return;
}   
void nameSortAddressBook(AddressBook* addressbook){
	Person* persons = addressbook->person;
	for (int i = 0; i < addressbook->size; i++){
		for (int j = addressbook->size - 1; j>0; j--){
			if (strcmp(persons[j-1].name, persons[j].name) > 0){
				Person temp = persons[j];
				persons[j] = persons[j - 1];
				persons[j - 1] = temp;
			}
		}
	}
	showPerson(addressbook);
	return;
}
int menu(){
	printf("====================\n");
	printf("0.�˳�\n");
	printf("1.�����ϵ��\n");
	printf("2.ɾ����ϵ��\n");
	printf("3.������ϵ��\n");
	printf("4.�޸���ϵ��\n");
	printf("5.��ʾ��ϵ��\n");
	printf("6.�����ϵ��\n"); 
	printf("7.����������������ϵ��\n");
	
	printf("====================\n");
	printf("������������ѡ��");
	int choice = 0;
	scanf("%d", &choice);
	/*while (choice<0 || choice>7){
	printf("������������,��������������ѡ��:");
	scanf("%d", choice);
	}*/
	return choice;
}

typedef void(*Point)(AddressBook*);
AddressBook addressbook;
int main()
{
	Point point[] = { NULL, addPerson, delPerson, findPerson,
		alterPerson, showPerson, clearPerson, nameSortAddressBook };
	initAddressBook(&addressbook);
	//addressbook.size = 0;

	while (1){
		int choice = menu();
		if (choice<0 || choice>7){
			printf("������������.\n");
			continue;
		}
		if (choice == 0){
			printf("GoodBye!\n");
			break;
		}
		point[choice](&addressbook);
	}
	system("pause");
	return 0;
}