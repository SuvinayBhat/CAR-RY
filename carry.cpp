#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//hospital  data storage application

struct node 
//patient node unke samaan ke liye
{
    string name;
    string ID;
    string critical;
    node* next;
    node* prev;
};


//global declaration - Linked List
node* HeadNormal;
node* TailNormal;
node* HeadCrit;
node* TailCrit;

int crit;
char input;
string entri;

//global declaration - Hashing
const char apahash[] = "!@#$%^&*()_+-=";
const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
const char uppercases[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int size = sizeof(apahash);
int sizelow = sizeof (lowercase);
int sizehigh = sizeof (uppercases);

struct hashnode
{
    string Hashtable;
    string TrueHash;
    hashnode* next;
    hashnode* prev;
};

hashnode* HashHead;
hashnode* HashTail;
int hashhash = 0; // hashlist hai


bool check(string entry)
{
    hashnode* go = HashHead;
    while (go != NULL)
    {
        if (entry == go->TrueHash)
        {
            return true;        
        }
        else
        {
            go = go->next;
        }
    }
    return false;
}
string Hashing(string entry)
{
    if (check(entry) == false)
    {
        string NewEntry = entry;
        string notjoji = "";
        acak :
            for (int j = 0; j < 4; j++)
            {
                notjoji = notjoji + apahash[rand()% :: size];
            }
            for (int k = 0; k<3; k++)
            {
                notjoji = notjoji + lowercase[rand()% :: sizelow];
            }


            for (hashnode* checkie = HashHead; checkie != NULL; checkie = checkie -> next)
                {
                    if(checkie -> Hashtable == notjoji)
                    {
                        goto acak;
                    }
                }

            hashnode *temp = new hashnode;
                temp -> TrueHash = entry;
                temp -> Hashtable = notjoji;
                hashhash = hashhash + 1;
                if (HashHead == NULL)
                {
                    temp ->next = NULL;
                    temp -> prev = NULL;
                    HashHead = temp;    
                    HashTail = HashHead;
                }
                else
                {
                    temp -> next = NULL;
                    HashTail ->next = temp;
                    temp ->prev = HashTail;
                    HashTail = temp;
                }
        
        return notjoji;
    }
    else if (check(entry) == true)
    {
        hashnode* search = HashHead;
        while (search != NULL)
        {
            if (entry == search->TrueHash)
            {
                return search->Hashtable;
            }
            else
            {
                search=search->next;
            }
        }
    }
}

void DisplayHash() //display hash queue
{
    hashnode* temp;
    temp = HashHead;
    int sno = 1;
    while (temp != NULL)
    {
        cout <<sno <<". " << temp->TrueHash << " -> "<< temp->Hashtable<<endl;
        temp = temp->next;
        sno = sno +1;
    }
}
void Display() //display queue
{
    node* tempNormal;
    node* tempCrit;
    tempNormal = HeadNormal;
    tempCrit = HeadCrit;
    int sno = 1;
    while (tempCrit != NULL)
    {
        cout << sno <<". " << tempCrit -> ID << " - "<<tempCrit -> name<< " - " << tempCrit->critical<<endl;
        tempCrit = tempCrit ->next;
        sno = sno +1;
    }
    while (tempNormal != NULL)
    {
        cout << sno <<". " << tempNormal -> ID << " - "<<tempNormal -> name<< " - " << tempNormal->critical<<endl;
        tempNormal = tempNormal ->next;
        sno = sno +1;
    }
}

void InsertNormalPatient(string entry, int crit) // regular patient ke liye insertion
//non critical piche se aayenge
{
    node* temp = new node;
    temp -> name = entry;
    temp->ID = Hashing(entry);
    if (crit == 2)
    {
        temp -> critical = "Inpatient";
    }
    else if (crit ==1)
    {
        temp -> critical = "Outpatient";
    }

    if (HeadNormal == NULL)
    {
        temp -> next = NULL;
        temp -> prev = NULL;
        HeadNormal = temp;
        TailNormal = HeadNormal;
    }

    else
    {
        TailNormal -> next = temp;
        temp -> next = NULL;
        temp -> prev = TailNormal;
        TailNormal = temp;
    }
}

void InsertEmergencyPatient(string entry, int crit)
{
    node* temp = new node;
    temp -> name = entry;
    temp -> ID = Hashing(entry);
    if (crit == 1)
    {
        temp -> critical = "Worrying";
    }
    else if (crit == 2)
    {
        temp -> critical = "Emergency";
    }
    else if (crit == 3)
    {
        temp -> critical = "Chronic";
    }

    if (HeadCrit == NULL)
    {
        temp -> next = NULL;
        temp -> prev = NULL;
        HeadCrit = temp;
        TailCrit = HeadCrit;
    }

    else
    {
        HeadCrit -> prev = temp;
        temp -> next = HeadCrit;
        temp -> prev = NULL;
        HeadCrit = temp;
    }
}

void mainMenu();

void NormalPatientList(){
    cout << "Enter the name of the patient you want to register for referral: "; 
    cin.ignore(); getline(cin, entri);
    cout << "Criticality Level: " << endl;
    cout << "1. Outpatient" << endl;
    cout << "2. Hospitalization" << endl;
    cout << "================================" << endl;
    cout << "Enter criticality level: ";
    cin >> crit;
    if (crit == 1) 
// outpatient
    {
        Hashing(entri);
            // queue mai nahi aayega inpatient hai
            // hashing will still run if patient not registered
    }
    else if (crit == 2) // normal hospitalization
    {
        InsertNormalPatient(entri, crit); //This goes to registering in the queue 
    }
    else
    {
        cout << "Incorrect input. Please repeat input." << endl;
        mainMenu();
    }
}

void EmergencyPatientList(){
    cout << "Enter the name of the patient you want to register for referral: "; 
    cin.ignore(); getline(cin, entri);
    cout << endl;
    cout << "Criticality Level: " << endl;
    cout << "1. Worrying" << endl;
    cout << "2. Emergency" << endl;
    cout << "3. Chronic" << endl;
    cout << "================================" << endl;
    cout << "Enter criticality level: ";
    cin >> crit;
    if (crit == 1)
    {
        
    }
    else if (crit == 3)
    {

    }
    else if (crit == 2 )
    {
        
    }
    else
    {
        cout << "Incorrect input. Please repeat input." << endl;
        mainMenu();
    }
    InsertEmergencyPatient(entri, crit); // this is the stack registration structure
}

void pop()
{
    if (HeadCrit != NULL)
    {
        if (HeadCrit ->next == NULL)
        {
            node* hatao=HeadCrit;
            HeadCrit = NULL;
            delete(hatao);
        }
        else
        {
            node* hatao=HeadCrit;
            HeadCrit = HeadCrit -> next;
            HeadCrit -> prev = NULL;
            delete(hatao);
        }
    }
    else
    {
        if (HeadNormal ->next == NULL)
        {
            HeadNormal = NULL;
        }
        else
        {
            HeadNormal = HeadNormal ->next;
            HeadNormal -> prev = NULL;
        }
    }
}

int main () 
    {
        mainMenu();
    }

void mainMenu(){
    
    MainMenu:
    system("cls");
    HashTableCheckPoint:
    cout << "=== Hospital Inpatient Administration Application ===" << endl;
    cout << "========================================================== ======" << endl;
    cout << "Inpatient queue: " << endl;
    Display();
    cout << "========================================================== ======" << endl;
    cout << "Main Menu : "<< endl;
    cout << "1. Register a normal patient queue" << endl;
    cout << "2. Register the emergency patient queue" << endl;
    cout << "3. Patient Checkout" << endl;
    cout << "4. Display key ID" << endl;
    cout << "9. Help" << endl;
    cout << "0. Exit" << endl;
    cout << "========================================================== ======" << endl;
    cout << "Entry: ";
    cin >> input;
    switch (input)
        {            
            case '0':
                cout << "================================ BYE BYE =====================================" << endl;
                int i, j, k, l, m, n, s, space, spa, sp;
    for (i = 1; i <= 5; i++)
    {
        // for T
        for (j = 1; j <= 5; j++)
        {
            if (i > 1 && (j == 2 || j == 1))
            {
                printf("  ");
            }
            if (i == 1 || j == 3)
            {
                printf("* ");
            }
            if (i > 1 && (j == 4 || j == 5))
            {
                printf("  ");
            }
        }
        printf(" ");
        // for H
        for (k = 1; k <= 5; k++)
        {
            if (k == 5 || i == 3 || k == 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }

        // for A
        for (space = 5; space >= i; space--)
        {
            printf(" ");
        }
        for (l = 1; l <= 5; l++)
        {
            if (l == 1)
            {
                printf("*");
            }
            if (i == 2 && l == 2)
            {
                printf(" *");
            }
            if (i == 3 && l == 2)
            {
                printf(" *");
            }
            if (i > 3 && l < 3)
            {
                for (spa = 3; spa <= i; spa++)
                {
                    printf(" ");
                }
            }
            if (i > 2 && l == 2)
            {
                printf(" *");
            }
        }
        for (space = 5; space >= i; space--)
        {
            printf(" ");
        }
        printf(" ");
        // for N
        for (m = 1; m <= 5; m++)
        {
            if (m == 1)
            {
                printf("* ");
            }
            if (m == 5)
            {
                printf("*  ");
            }
            if (m != i && m != 5 && m != 1)
            {
                printf("  ");
            }
            if (m == i && m != 1 && m != 5)
            {
                printf("* ");
            }
        }
        // for K
        for (n = 1; n <= 5; n++)
        {
            if (n == 1)
            {
                printf("* ");
            }
            if ((i == 1 || i == 2) && n == 2)
            {
                for (sp = 2; sp >= i; sp--)
                {
                    printf(" ");
                }
                printf("*");
            }
            if (i == 3 && n == 2)
            {
                printf("*");
            }
            if ((i == 4 || i == 5) && n == 2)
            {
                for (sp = 4; sp <= i; sp++)
                {
                    printf(" ");
                }
                printf("*");
            }
        }
        if (i < 4)
        {
            for (sp = 1; sp <= i; sp++)
            {
                printf(" ");
            }
        }
        if (i > 3)
        {
            for (sp = 5; sp >= i; sp--)
            {
                printf(" ");
            }
        }
        printf(" ");
        // for S
        for (s = 1; s <= 5; s++)
        {
            if (i != 2 && i != 4)
            {
                printf("* ");
            }
            if (i == 2 && s == 1)
            {
                printf("* ");
            }
            if (i == 4 && s == 1)
            {
                printf("        *");
            }
        }
        printf("\n");
    }
                cout << "Made by Suvinay, Yatharth, Shivam and Lakshita" << endl;
                cout << "==============================================================================" << endl;
                break;
                
            case '1':
                NormalPatientList();
                goto MainMenu;
                break;

            case '2':
                EmergencyPatientList();
                goto MainMenu;
                break;

            case '3': // POP
                pop();
                goto MainMenu;
                break;
                
            case '4': // displays patient data called by ID
                cout << "KEY:" << endl;
                DisplayHash();
                cout << endl;
                goto HashTableCheckPoint;
                break;

            case '9' :
                
                cout << "Inpatient Administration Application Instructions" << endl;
                cout << "1. Select the Patient List Menu\n";
                cout << "2. Enter the patient's identity\n";
                cout << "3. Select patient treatment category\n";
                cout << "4. After the patient is allowed to go home, check out the hospital\n";
                cout << "5. Please select menu number 4 to check patient ID\n";
                cout << "\nIf you have further questions, please contact\n";
                cout << "call center via number 52102605";

            default:
                break;
        }
}