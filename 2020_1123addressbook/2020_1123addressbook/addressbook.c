//通讯录
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
	//通讯录中有效的联系人个数
	int size;
}AddressBook;
void initAddressBook(AddressBook* addressbook){
	addressbook->size = 0;
}
void addPerson(AddressBook* addressbook){
	printf("添加联系人\n");
	if (addressbook->size >= PERSON_MAX){
		printf("通讯录已满,添加失败\n");
		return;
	}
	Person* person=&addressbook->person[addressbook->size];
	printf("请输入联系人的姓名\n");
	scanf("%s", person->name);
	printf("请输入联系人的性别\n");
	scanf("%s", person->sex);
	printf("请输入联系人的年龄\n");
	scanf("%d", &person->age);
	printf("请输入联系人的电话\n");
	scanf("%s", person->telephone);
	printf("请输入联系人的地址\n");
	scanf("%s", person->address);

	addressbook->size++;
	printf("添加联系人成功\n");
	return;
}
void delPerson(AddressBook* addressbook){
	printf("请输入要删除的联系人的序号:");
	int number = 0;
	scanf("%d", &number);
	if (number < 0 || number >= addressbook->size){
		printf("不存在该序号的联系人\n");
		return;
	}
	printf("确定删除[%d]号联系人吗? (y/n):",number);
	char choice[1024] = "n";
	scanf("%s", choice);
	if (strcmp(choice, "y") || strcmp(choice, "yes")){
		addressbook->person[number] = addressbook->person[addressbook->size-1];
		addressbook->size--;
		printf("该联系人已删除\n");
	}
	return;
}
void findPerson(AddressBook* addressbook){
	printf("请输入要查找的联系人的序号:");
	int number = 0;
	scanf("%d", &number);
	if (number < 0 || number >= addressbook->size){
		printf("不存在该序号的联系人\n");
		return;
	}

	printf("序号\t姓名\t\t性别\t年龄\t电话\t\t地址\n");
		printf("[%d]\t%s\t\t%s\t%d\t%s\t%s\n", number,
			addressbook->person[number].name,
			addressbook->person[number].sex, addressbook->person[number].age,
			addressbook->person[number].telephone, addressbook->person[number].address
			);
}
void alterPerson(AddressBook* addressbook){
	printf("请输入要修改的联系人的序号:");
	int number = 0;
	scanf("%d", &number);
	if (number < 0 || number >= addressbook->size){
		printf("不存在该序号的联系人\n");
		return;
	}

	Person* person = &addressbook->person[number];
	printf("请输入联系人的姓名\n");
	scanf("%s", person->name);
	printf("请输入联系人的性别\n");
	scanf("%s", person->sex);
	printf("请输入联系人的年龄\n");
	scanf("%d", &person->age);
	printf("请输入联系人的电话\n");
	scanf("%s", person->telephone);
	printf("请输入联系人的地址\n");
	scanf("%s", person->address);

	printf("修改联系人成功\n");
	return;
}
void showPerson(AddressBook* addressbook){
	if (addressbook->size == 0){
		printf("当前通讯录为空\n");
		return;
	}
	printf("序号\t姓名\t\t性别\t年龄\t电话\t\t地址\n");
	for (int i = 0; i < addressbook->size; i++){
		printf("[%d]\t%s\t\t%s\t%d\t%s\t%s\n", i,
			addressbook->person[i].name,
			addressbook->person[i].sex, addressbook->person[i].age,
			addressbook->person[i].telephone, addressbook->person[i].address
			);
	}
	printf("该通讯录共[%d]个联系人\n", addressbook->size);
	return;
}

void clearPerson(AddressBook* addressbook){
	printf("确定清空吗? (y/n) :");
	char choice[1024]="no";
	scanf("%s", choice);
	if (strcmp(choice ,"y")==0||strcmp(choice,"yes")==0){
		addressbook->size = 0;
		printf("通讯录已清空\n");
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
	printf("0.退出\n");
	printf("1.添加联系人\n");
	printf("2.删除联系人\n");
	printf("3.查找联系人\n");
	printf("4.修改联系人\n");
	printf("5.显示联系人\n");
	printf("6.清空联系人\n"); 
	printf("7.以名字排序所有联系人\n");
	
	printf("====================\n");
	printf("请输入与您的选择：");
	int choice = 0;
	scanf("%d", &choice);
	/*while (choice<0 || choice>7){
	printf("您的输入有误,请重新输入您的选择:");
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
			printf("您的输入有误.\n");
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