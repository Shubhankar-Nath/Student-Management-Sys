#include<iostream>
#include<conio.h>
#include<SQLAPI.h> //  main SQLAPI++ header
#include<string.h>
#include<mysql.h>
#include<iomanip>
#include<stdio.h>
using namespace std;

string fname,lname,sapid,sem,age,cgpa;

void main()
{
      SAConnection con;   // create connection object -con is variable
      v// connect to MySQL database
      con.Connect(
      "abc",  // database name change as per your database  name
      "root",   //default user name
      "1234",       // password for my database
      SA_MySQL_Client);

      SACommand cmd;    // create command object

	    void add()
    	{
            clrscr();
            cout<<"\nEnter first name\n"<<endl;
            cin(fname);
            cout<<"\nEnter Last name"<<endl;
            cin(lname);
            cout<<"\nEnter Sap id"<<endl;
            cin>>sapid;		
	    	cout<<"\nEnter Semester"<<endl;
	    	cin>>sem;
	    	cout<<"\nInsert Age"<<endl;
	    	cin>>age;
	    	cout<<"\nEnter CGPA"<<endl;
	    	cin>>cgpa;
    
            // insert value
            cmd.setCommandText( "Insert into student (sap, fname, lname, age, sem, cgpa) values (:3,:1,:2,:5,:4,:6)";
            cmd.Param(1).setAsString()=fname.c_str();
            cmd.Param(2).setAsString()=lname.c_str();
            cmd.Param(3).setAsString()=sapid.c_str();
            cmd.Param(4).setAsString()=sem.c_str();
            cmd.Param(5).setAsString()=age.c_str();
            cmd.Param(6).setAsString()=cgpa.c_str();
    
            cmd.Execute();
    
            // commit changes on success
            con.Commit();
            cout<<"\nRow Created!\n";
            getch();
    
            goto a;//jumping to main menu
    
	    }

        void del()
        {
        	clrscr();
            cout<<"Enter the SAP ID of the student you want to delete record of\n";
        	cin>>sapid;
        	//delete value
        	cmd.setCommandText("delete from student where sap=:7");
            cmd.Param(7).setAsString()=sapid.c_str();
	        cmd.Execute();

           // commit changes on success
           con.Commit();
           getch();
           goto a;//jumping to main menu
        }

        void modify()
        {
            clrscr();
                    cout<<"\nEnter the SAP ID of the student\n";
            cin>>sapid;
            cout<<"Select the catagory you want to alter by pressing the number against it:\n";
            cout<<"\n\t\t1.CGPA\n\t\t2.Semester of study\n\t\t3.Name\n\t\t4.Age"<<endl;
            int a;
            cin>>a;
            switch(a)
            {
              case 1:cout<<"\n Enter the CGPA";
                       cmd.setCommandText("Update student set cgpa= :9 where sap=:8")
                       cmd.Param(8).setAsString()=sapid.c_str();
                       cmd.Param(9).setAsString()=cgpa.c_str();
        	           cmd.Execute();
                       con.Commit();
                       break;
              case 2:cout<<"\n Enter the Semester of study";
                       cmd.setCommandText("Update student set sem= :10 where sap=:11")
                       cmd.Param(11).setAsString()=sapid.c_str();
                       cmd.Param(10).setAsString()=sem.c_str();
	                   cmd.Execute();
                       con.Commit();
                       break;
              default:cout<<"Worng input! Start again....";
                        getch();
                        goto a;
            }
        } 

        void view()
        {
            clrscr();
            cout<<"\nEnter the Sap Id of the record you want to view\n";
            cin>>sapid;
            cmd.setCommandText("select from student where sap=:8");
            cmd.Param(8).setAsString()=sapid.c_str();
        	cmd.Execute();
            getch();
            goto a;

        }

        void view_all()
        {   
            clrscr();
            cmd.setCommandText("select* from student");
            cmd.Execute();
            getch();
            goto a;

        } 

    int choice;      

    a: 
    cout<<"\n\n\n\n";
    cout<<" ###################>  STUDENT MANAGEMENT SYSTEM  <###################"<<endl;
    cout<<" ===================================================================== \n\n";
    cout<<"Main Menu {Enter your choice} \n ";
    cout<<"\n";
   
    cout<<"\t\t1.Add record\n\t\t2.Delete record\n\t\t3.Modify record\n\t\t4.View record\n\t\t5.View all\n\t\t.6Exit";
    cin>>choice;
    switch(choice)
    {	
        case 1:add();
  		       break;
        case 2:del();
  		       break;
        case 3:Modify();
               break;
        case 4:View();
               break;
  	    case 5:view_all();
               break;
	    case 6:exit(0);
               break;

        default:
                cout<< "\nEnter a valid option";
                getch();
                goto a;         
 		
     }


}
