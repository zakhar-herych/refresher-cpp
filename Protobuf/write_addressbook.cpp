#include <iostream>
#include <fstream>
#include <string>
#include "addressbook.pb.h"
using namespace std;

void write_addressbook(const tutorial::AddressBook& addressbook){
	for (int i=0; i<addressbook.person_size(); i++){
		const tutorial::Person& person = addressbook.person(i);
		if (i!=0){
			cout << endl;
		}
		cout << "Person id:\t" << person.id() << endl;
		cout << "Person name:\t" << person.name() << endl;
		if (person.has_email()){
			cout << "Email address:\t" << person.email() << endl;
		}

		for (int j=0; j<person.phone_size(); j++){
			const tutorial::Person::PhoneNumber& phone_number = person.phone(j);

			switch(phone_number.type()){
				case tutorial::Person::HOME:
					cout << "Home number:\t";
					break;
				case tutorial::Person::WORK:
					cout << "Work number:\t";
					break;
				case tutorial::Person::MOBILE:
					cout << "Mobile number:\t";
					break;
				default:
					break;
			}
			cout << phone_number.number() << endl;
		}
	}
}

int main(int argc, char* argv[]){
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	if (argc!=2){
		cerr << "Usage: " << argv[0] << " ADDRESS_BOOK_FILE" << endl;
		return -1;
	}

	tutorial::AddressBook address_book;

	fstream input(argv[1], ios::in | ios::binary);
	if (!address_book.ParseFromIstream(&input)){
		cerr << "Failed to pass address book." << endl;
		return -1;
	}

	write_addressbook(address_book);

	google::protobuf::ShutdownProtobufLibrary();
	return 0;
}
