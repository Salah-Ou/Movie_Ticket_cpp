#include <iostream>
#include <iomanip>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

int main();
void Time();

int gotoxy(int x , int y){
    COORD coord ;
    coord.X = x ;
    coord.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return 0 ;
}

class Movie {
    private : 
        struct Ticket {
            string name ;
            int ticket_no ;
            float price ;
            string release_date ;
            int quantity ;
        };
        vector <Ticket> ticket ;

    public : 

        void Login(){
            system("cls");
            Time();
            gotoxy(24,2);
            cout << "\033[1;30m-----------------------------------\n";
            gotoxy(30,3);
            cout << "\033[1;32m USER PANEL  -  LOGIN \033[0m\n" ;
            gotoxy(24,4);
            cout << "\033[1;30m-----------------------------------\033[0m";
            gotoxy(28,6);
            cout << "\033[1;34mUSERNAME : \033[0m";
            string username;
            cin >> username;
            string password ;
            int password_size = 10 ;
            password.clear();
            char ch ;
            gotoxy(28,8);
            cout << "\033[1;34mPASSWORD : \033[0m" ;
            for(int i = 0 ; i < password_size ; i++){
                ch = _getch();
                if(ch == 13) break ;
                cout << "*" ;
                password += ch ;
            }
            if (password == "12345"){
                gotoxy(34,10);
                cout << "\033[1;32mLogin Successful  !\033[0m" ;
                Sleep(1500);
                menu();
            }
            else{
                gotoxy(36,10);
                cout << "\033[1;31mLogin Failed  !\033[0m" ;
                gotoxy(28,12);
                cout << "\033[30mPress any key to try again!.... " ;
                _getch();
                Sleep(1000);
                main();
            }
        }

        void menu(){
            int choice ;
            system("cls");
            Time();
            gotoxy(24,2);
            cout << "\033[1;30m-----------------------------------\n" ;
            gotoxy(26,3);
            cout << "\033[1;0m MOVIE TICKET MANAGEMENT SYSTEM \n" ;
            gotoxy(24,4);
            cout << "\033[1;30m-----------------------------------\n" ;
            gotoxy(28,6);
            cout << "\033[1;33m 1. Add Ticket.\n" ;
            gotoxy(28,8);
            cout << "\033[1;33m 2. Edit Ticket.\n" ;
            gotoxy(28,10);
            cout << "\033[1;33m 3. Remove Ticket.\n" ;
            gotoxy(28,12);
            cout << "\033[1;33m 4. Show All Tickets.\n" ;
            gotoxy(28,14);
            cout << "\033[1;33m 5. Quit.\n" ;
            gotoxy(24,16); 
            cout << "\033[1;30m--------------------------------\n" ;
            gotoxy(28,18);
            cout << "\033[1;0m Enter your choice : " ;
            cin >> choice ;
            switch(choice){
                case 1 : 
                    add_ticket();
                    break ;
                case 2 : 
                    edit_ticket();
                    break ;
                case 3 : 
                    remove_ticket();
                    break ;
                case 4 : 
                    show_all_tickets();
                    break ;
                case 5 : 
                    exit(0);
                default : 
                    gotoxy(28,20);
                    cout << "\033[1;31mInvalid Choice!\033[0m" ;
            }
        }

        void add_ticket(){
            system("cls");
            Time();
            gotoxy(24,2);
            cout << "\033[1;30m-----------------------------------\n" ;
            gotoxy(35,3);
            cout << "\033[0m ADD TICKET \n" ;
            gotoxy(24,4);
            cout << "\033[1;30m-----------------------------------\n" ;
            Ticket t ;
            gotoxy(28,6);
            cout << "Enter Ticket No : " ;
            cin >> t.ticket_no ;
            gotoxy(28,8);
            cout << "Enter The Name of the Movie : " ;
            cin.ignore();
            getline(cin,t.name);
            gotoxy(28,10);
            cout << "Enter Releasing Date (DD/MM/YYYY) : " ;
            cin >> t.release_date ;
            gotoxy(28,12);
            cout << "Enter Ticket Price : " ;
            cin >> t.price ;
            gotoxy(28,14);
            cout << "Enter Quantity : " ;
            cin >> t.quantity ;
            ticket.push_back(t);
            gotoxy(26,16);
            cout << "\033[1;32mTicket Added Successfully!\033[0m" ;
            gotoxy(26,19);
            cout << "\033[0mPress any key to continue Program... " ;
            _getch();
            Sleep(1500);
            menu();
        }

        void edit_ticket(){
            system("cls");
            Time();
            if (ticket.empty()){
                gotoxy(22,8);
                cout << "\033[1;30m---------------------------------------------" ;
                gotoxy(28,9);
                cout << "\033[1;30mNo Movie Ticket Available In List.\n" ;
                gotoxy(22,10);
                cout << "\033[1;30m---------------------------------------------" ;
            }
            else{
                int no ;
                gotoxy(24,2);
                cout << "\033[1;30m-----------------------------------\n" ;
                gotoxy(36,3);
                cout << "\033[0m EDIT  TICKET \n" ;
                gotoxy(24,4);
                cout << "\033[1;30m-----------------------------------\n" ;
                gotoxy(28,6);
                cout << "Enter Ticket No To Edit : " ;
                cin >> no ;
                for(int i = 0 ; i < ticket.size() ; i++){
                    if(ticket[i].ticket_no == no){
                        gotoxy(28,8);
                        cout << "Enter New The Name of the Movie : " ;
                        cin.ignore();
                        getline(cin,ticket[i].name);
                        gotoxy(28,10);
                        cout << "Enter New Releasing Date (DD/MM/YYYY) : " ;
                        cin >> ticket[i].release_date ;
                        gotoxy(28,12);
                        cout << "Enter New Ticket Price : " ;
                        cin >> ticket[i].price ;
                        gotoxy(28,14);
                        cout << "Enter New Quantity : " ;
                        cin >> ticket[i].quantity ;
                    }
                    else{
                        gotoxy(28,16);
                        cout << "\033[1;31mTicket Not Found In List.\033[0m" ;
                    }
                }
            }
            gotoxy(26,19);
            cout << "\033[0mPress any key to continue Program... " ;
            _getch();
            Sleep(1000);
            menu();
        }

        void remove_ticket(){
            system("cls");
            Time();
            if (ticket.empty()){
                gotoxy(22,8);
                cout << "\033[1;30m---------------------------------------------" ;
                gotoxy(28,9);
                cout << "\033[1;30mNo Movie Ticket Available In List.\n" ;
                gotoxy(22,10);
                cout << "\033[1;30m---------------------------------------------" ;
            }
            else{
                int no ;
                gotoxy(24,2);
                cout << "\033[1;30m-----------------------------------\n" ;
                gotoxy(36,3);
                cout << "\033[0m REMOVE  TICKET \n" ;
                gotoxy(24,4);
                cout << "\033[1;30m-----------------------------------\n" ;
                gotoxy(28,6);
                cout << "Enter Ticket No To Remove : " ;
                cin >> no ;
                for(int i = 0 ; i < ticket.size() ; i++){
                    if(ticket[i].ticket_no == no){
                        ticket.erase(ticket.begin() + i);
                        gotoxy(28,8);
                        cout << "\033[1;32mTicket Removed Successfully!\033[0m" ;
                    }
                    else{
                        gotoxy(28,10);
                        cout << "\033[1;31mTicket Not Found In List.\033[0m" ;
                    }
                }
            }
            gotoxy(26,12);
            cout << "\033[0mPress any key to continue Program... " ;
            _getch();
            Sleep(1000);
            menu();
        }

        void show_all_tickets(){
            system("cls");
            Time();
            if (ticket.empty()){
                gotoxy(22,8);
                cout << "\033[1;30m---------------------------------------------" ;
                gotoxy(28,9);
                cout << "\033[1;30mNo Movie Ticket Available In List.\n" ;
                gotoxy(22,10);
                cout << "\033[1;30m---------------------------------------------" ;
            }
            else{
                gotoxy(24,2);
                cout << "\033[1;30m-----------------------------------\n" ;
                gotoxy(33,3);
                cout << "\033[0m SHOW ALL TICKETS \n" ;
                gotoxy(24,4);
                cout << "\033[1;30m-----------------------------------\n" ;
                gotoxy(7,6);
                cout << setw(5) << "Ticket No" << setw(15) << "Movie Name" << setw(20) << "Releasing Date" 
                << setw(13) << "Price" << setw(15) <<"Quantity" << endl ;
                gotoxy(7,7);
                cout << "----------------------------------------------------------------------------------------" << endl ;
                for(int i = 0 ; i < ticket.size() ; i++){
                    gotoxy(7,8 + i*2);
                    cout << setw(5) << ticket[i].ticket_no << setw(21) << ticket[i].name << setw(16) 
                    << ticket[i].release_date << setw(14) << ticket[i].price * ticket[i].quantity << " DH " << setw(9) << ticket[i].quantity << endl ;
                }
                gotoxy(7,7);
                cout << "----------------------------------------------------------------------------------------" << endl ;
            }
            gotoxy(26,12);
            cout << "\033[0mPress any key to continue Program... " ;
            _getch();
            Sleep(1000);
            menu();
        }
};

void Time(){
    time_t now = time(0);
    tm* local = localtime(&now);
    gotoxy(1,0);
    cout << "\033[1;38mCurrent Time : " << asctime(local) << "\033[0m";
}

int main(){
    system("cls");
    Time();
    Movie m ;
    m.Login();
    return 0 ;
}