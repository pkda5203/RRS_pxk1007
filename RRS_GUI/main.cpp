#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <FL/Fl.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Text_Display.H>


using namespace std;



Fl_Window win(800, 600, "Robbie Robot Shop---Login As");

void Button_PM1(Fl_Widget *win, void*);
void Button_PM(Fl_Widget *win, void*);
void Button_SA(Fl_Widget *win, void*);
void Button_BC(Fl_Widget *win, void*);
void Button_PB(Fl_Widget *win, void*);
void Button_Order(Fl_Widget *sa_win, void*);
void Button_Bill(Fl_Window *sa_win, void*);
void Button_View_Order(Fl_Widget *bc_win, void*);
void Button_Browse(Fl_Window *bc_win, void*);
void Button_RPart1(Fl_Widget *pm_win, void*);
void Button_RPart2(Fl_Widget *pm_win, void*);
void Button_RPart3(Fl_Widget *pm_win, void*);
void Button_RPart4(Fl_Widget *pm_win, void*);
void Button_RPart6(Fl_Widget *pm_win, void*);
void Button_RPart7(Fl_Widget *pm_win, void*);
void Button_close(Fl_Widget *pm_win, void*);
void create_partCB(Fl_Window *g, void*);
void create_part4CB(Fl_Window *g, void*);
void create_part6CB(Fl_Window *g, void*);
void create_part7CB(Fl_Window *g, void*);
void create_part0CB(Fl_Window *g, void*);
void create_part1CB(Fl_Window *g, void*);
void create_part5CB(Fl_Window *g, void*);
void order_modelCB(Fl_Widget *w, void*);
void Button_RModel(Fl_Window *pm_win, void*);
void create_modelCB(Fl_Widget *w, void*);
void Button_ex(Fl_Widget *pm_win, void*);
Fl_Window *dialog;
Fl_Window *rm_dialog;
Fl_Window *rp_dialog;
Fl_Window *order_dialog;
Fl_Window *brow;

Fl_Window *dialog1;
Fl_Box *box1;
Fl_Box *box2;
Fl_Box *box3;
Fl_Box *box4;
Fl_Box *box5;
Fl_Box *box6;
Fl_Box *box7;
Fl_Box *box8;
Fl_Input *rp_name;
Fl_Input *rp_number;
Fl_Input *rp_type;
Fl_Input *rp_weight;
Fl_Input *rp_cost;
Fl_Input *rp_pow;
Fl_Input *rp_ener;
Fl_Input *rp_arms;
Fl_Input *rp_batt;
Fl_Input *rp_desc;
Fl_Input *rm_name;
Fl_Input *rm_number;
Fl_Input *rm_part1;
Fl_Input *rm_part2;
Fl_Input *rm_part3;
Fl_Input *rm_part4;
Fl_Input *rm_part5;
Fl_Input *rm_part6;


void Button_PM(Fl_Widget *win, void*)
{
	Fl_Window *pm_win = new Fl_Window(250, 250, "RRS --- Product Manager:");
	
	Fl_Button *rp = new Fl_Button(50,90,150,40,"Create Robot Part");
	Fl_Button *rm = new Fl_Button(50,150,150,40,"Create Robot Model");
	
	pm_win->end();

	rp->callback((Fl_Callback*) Button_PM1);
	rm->callback((Fl_Callback*) Button_RModel);
	pm_win->show();

};

void Button_PM1(Fl_Widget *win, void*)
{
	rp_dialog= new Fl_Window(400, 310, "Create Parts");
	

	Fl_Button *ch = new Fl_Button(100,40,200,30,"Create Head");
	Fl_Button *ca = new Fl_Button(100,80,200,30,"Create Arm");
	Fl_Button *ct = new Fl_Button(100,120,200,30,"Create Torso");
	Fl_Button *cl = new Fl_Button(100,160,200,30,"Create Locomoter");
	Fl_Button *cb = new Fl_Button(100,200,200,30,"Create Battery");
	Fl_Button *ex = new Fl_Button(100,240,200,30,"Close");
	
	
	

	ch->callback((Fl_Callback*) Button_RPart1);
	ct->callback((Fl_Callback*) Button_RPart4);
	ca->callback((Fl_Callback*) Button_RPart3);
	cl->callback((Fl_Callback*) Button_RPart6);
	cb->callback((Fl_Callback*) Button_RPart7);
	ex->callback((Fl_Callback*) Button_ex);
	
	
	rp_dialog->show();
rp_dialog->end();

};


void Button_RPart(Fl_Widget *pm_win, void*)
{
	dialog = new Fl_Window(500,370,"Create Robot Part: Head");
	rp_name = new Fl_Input(200, 10, 210, 25, "Enter this head's name: ");
		rp_name->align(FL_ALIGN_LEFT);
	
		rp_number = new Fl_Input(200, 40, 210, 25, "Enter model number: ");
		rp_number->align(FL_ALIGN_LEFT);
		rp_weight = new Fl_Input(200, 70, 210, 25, "Weight: ");
		rp_weight->align(FL_ALIGN_LEFT);
		rp_cost = new Fl_Input(200, 100, 210, 25, "Enter this head's cost: ");	
		rp_cost->align(FL_ALIGN_LEFT);
		rp_pow = new Fl_Input(200, 130, 210, 25, "Enter this head's power: ");
		rp_pow->align(FL_ALIGN_LEFT);	
		rp_desc = new Fl_Multiline_Input(200, 160, 210, 75, "Description: ");
		rp_desc->align(FL_ALIGN_LEFT);
		Fl_Button *rp_create = new Fl_Button(200, 300, 120, 25, "Create");
		rp_create->callback((Fl_Callback*) create_part4CB, 0);
		dialog->end();

		dialog->show();
};

void Button_ex(Fl_Widget *pm_win, void*)
{
	

		rp_dialog->hide();
};




void Button_RPart1(Fl_Widget *pm_win, void*)
{
	dialog = new Fl_Window(400,400,"Create Robot Part: Head");
	rp_name = new Fl_Input(120, 10, 210, 25, "Name: ");
		rp_name->align(FL_ALIGN_LEFT);
	
		rp_number = new Fl_Input(120, 40, 210, 25, "Part Number: ");
		rp_number->align(FL_ALIGN_LEFT);
		rp_weight = new Fl_Input(120, 70, 210, 25, "Weight: ");
		rp_weight->align(FL_ALIGN_LEFT);
		rp_cost = new Fl_Input(120, 100, 210, 25, "Cost: ");	
		rp_cost->align(FL_ALIGN_LEFT);
		rp_pow = new Fl_Input(120, 130, 210, 25, "Power: ");
		rp_pow->align(FL_ALIGN_LEFT);	
		rp_desc = new Fl_Multiline_Input(120, 160, 210, 75, "Description: ");
		rp_desc->align(FL_ALIGN_LEFT);
		Fl_Button *rp_create = new Fl_Button(145, 330, 120, 25, "Create");
		rp_create->callback((Fl_Callback*) create_partCB, 0);
		dialog->end();
		dialog->show();
};

void Button_RPart2(Fl_Widget *pm_win, void*)
{
	win.hide();
};


void Button_RPart3(Fl_Widget *pm_win, void*)
{
	dialog = new Fl_Window(400,400,"Create Robot Part: Arm");
	rp_name = new Fl_Input(120, 10, 210, 25, "Name: ");
		rp_name->align(FL_ALIGN_LEFT);
	
		rp_number = new Fl_Input(120, 40, 210, 25, "Model Number: ");
		rp_number->align(FL_ALIGN_LEFT);
		rp_cost = new Fl_Input(120, 70, 210, 25, "Cost: ");	
		rp_cost->align(FL_ALIGN_LEFT);
		rp_pow = new Fl_Input(120, 100, 210, 25, "Max Power: ");
		rp_pow->align(FL_ALIGN_LEFT);	
		rp_desc = new Fl_Multiline_Input(120, 130, 210, 75, "Description: ");
		rp_desc->align(FL_ALIGN_LEFT);
		Fl_Button *rp_create = new Fl_Button(145, 330, 120, 25, "Create");
		rp_create->callback((Fl_Callback*) create_part1CB, 0);

		dialog->end();

		dialog->show();
};

void Button_close(Fl_Widget *pm_win, void*)
{
	
		pm_win->hide();
};

void Button_RPart4(Fl_Widget *pm_win, void*)
{
	dialog = new Fl_Window(400,400,"Create Robot Part: Torso");
	rp_name = new Fl_Input(150, 10, 210, 25, "Name: ");
		rp_name->align(FL_ALIGN_LEFT);
	
		rp_number = new Fl_Input(150, 40, 210, 25, "Model Number: ");
		rp_number->align(FL_ALIGN_LEFT);
		rp_cost = new Fl_Input(150, 70, 210, 25, "Cost: ");	
		rp_cost->align(FL_ALIGN_LEFT);
		rp_arms = new Fl_Input(150, 100, 210, 25, "Max Arms(0-2): ");
		rp_arms->align(FL_ALIGN_LEFT);	
		rp_batt = new Fl_Input(150, 130, 210, 25, "Max Batteries(1-3): ");
		rp_batt->align(FL_ALIGN_LEFT);
		rp_desc = new Fl_Multiline_Input(150, 160, 210, 75, "Description: ");
		rp_desc->align(FL_ALIGN_LEFT);
		Fl_Button *rp_create = new Fl_Button(145, 330, 120, 25, "Create");
		rp_create->callback((Fl_Callback*) create_part5CB, 0);

		dialog->end();

		dialog->show();
};

void Button_RPart6(Fl_Widget *pm_win, void*)
{
	dialog = new Fl_Window(400,400,"Create Robot Part: Locomoter");
	rp_name = new Fl_Input(150, 10, 210, 25, "Name: ");
		rp_name->align(FL_ALIGN_LEFT);
	
		rp_number = new Fl_Input(150, 40, 210, 25, "Model Number: ");
		rp_number->align(FL_ALIGN_LEFT);
		rp_cost = new Fl_Input(150, 70, 210, 25, "Cost: ");	
		rp_cost->align(FL_ALIGN_LEFT);
		rp_pow = new Fl_Input(150, 100, 210, 25, "Max Power: ");
		rp_pow->align(FL_ALIGN_LEFT);	
		rp_desc = new Fl_Multiline_Input(150, 130, 210, 75, "Description: ");
		rp_desc->align(FL_ALIGN_LEFT);
		Fl_Button *rp_create = new Fl_Button(145, 330, 120, 25, "Create");
		rp_create->callback((Fl_Callback*) create_part6CB, 0);

		dialog->end();

		dialog->show();
};

void Button_RPart7(Fl_Widget *pm_win, void*)
{
	dialog = new Fl_Window(400,400,"Create Robot Part: Battery");
	rp_name = new Fl_Input(150, 10, 210, 25, "Name: ");
		rp_name->align(FL_ALIGN_LEFT);
	
		rp_number = new Fl_Input(150, 40, 210, 25, "Model Number: ");
		rp_number->align(FL_ALIGN_LEFT);
		rp_cost = new Fl_Input(150, 70, 210, 25, "Cost: ");	
		rp_cost->align(FL_ALIGN_LEFT);
		rp_ener = new Fl_Input(150, 100, 210, 25, "Max Energy: ");
		rp_ener->align(FL_ALIGN_LEFT);	
		rp_pow = new Fl_Input(150, 130, 210, 25, "Power available: ");
		rp_pow->align(FL_ALIGN_LEFT);
		rp_desc = new Fl_Multiline_Input(150, 160, 210, 75, "Description: ");
		rp_desc->align(FL_ALIGN_LEFT);
		Fl_Button *rp_create = new Fl_Button(145, 330, 120, 25, "Create");
		rp_create->callback((Fl_Callback*) create_part7CB, 0);

		dialog->end();

		dialog->show();
};


void Button_RModel(Fl_Window *pm_win, void*)
{
		rm_dialog = new Fl_Window(480,390,"Create Robot Model");
	
		rm_name = new Fl_Input(200, 10, 210, 25, "Name: ");
		rm_name->align(FL_ALIGN_LEFT);
		rm_number = new Fl_Input(200, 40, 210, 25, "Model Number: ");
		rm_number->align(FL_ALIGN_LEFT);
		rm_part1 = new Fl_Input(200, 70, 210, 25, "Head Part Name: ");
		rm_part1->align(FL_ALIGN_LEFT);
		rm_part2 = new Fl_Input(200, 100, 210, 25, "Torso Part Name: ");
		rm_part2->align(FL_ALIGN_LEFT);
		rm_part3 = new Fl_Input(200, 130, 210, 25, "Left Arm Part: ");
		rm_part3->align(FL_ALIGN_LEFT);
		rm_part4 = new Fl_Input(200, 160, 210, 25, "Right Arm Part: ");
		rm_part4->align(FL_ALIGN_LEFT);
		rm_part5 = new Fl_Input(200, 190, 210, 25, "Locomotor Part Name: ");
		rm_part5->align(FL_ALIGN_LEFT);
		rm_part6 = new Fl_Input(200, 220, 210, 25, "Battery Part Name: ");
		rm_part6->align(FL_ALIGN_LEFT);
				
		Fl_Button *rm_create = new Fl_Button(200, 330, 120, 25, "Create");
		rm_create->callback((Fl_Callback*) create_modelCB,0);
		
		

		rm_dialog->end();
		rm_dialog->show();
};


void create_modelCB(Fl_Widget *w, void*)
{
	fstream file2("data.csv", ios::in | ios:: out | ios::app);
	fstream file3("models.csv", ios::in | ios::out | ios::app);
			
	string name, number, type, weight, cost, img, desc;
	double tot_cost = 0.0;	

	while(file2 >> name >> number >> type >> weight >> cost >> img >> desc)
	{
		int money = (int) atoi(cost.c_str());
		if(name == rm_part1->value())
			tot_cost +=  money;
		if(name == rm_part2->value())
			tot_cost += money;		
		if(name == rm_part3->value())
			tot_cost += money;		
		if(name == rm_part4->value())
			tot_cost += money;
		if(name == rm_part5->value())
			tot_cost += money;		
		if(name == rm_part6->value())
			tot_cost += money;		
	}
	
	if(file3.is_open())
	{
		file3 << rm_name->value() << " " << rm_number->value() << " " << tot_cost << " "<< rm_part1->value() << " " << rm_part2->value() << " " << rm_part3->value() << " " << rm_part4->value() << " " << rm_part5->value() << " " << rm_part6->value() << "\n";
	}
	file2.close();
	file3.close();
	string result9;
	result9.append("Name: ");
	result9.append(rm_name->value());
        result9.append("\nModel number: ");
	result9.append(rm_number->value());
	result9.append("\nHead Name: ");
	result9.append(rm_part1->value());
 result9.append("\nTorso Name: ");
	result9.append(rm_part2->value());
 result9.append("\nLeft Arm Name: ");
	result9.append(rm_part3->value());
 result9.append("\nRight Arm Name: ");
	result9.append(rm_part4->value());
 result9.append("\nLocomoter Name: ");
	result9.append(rm_part5->value());
 result9.append("\nBattery Name: ");
	result9.append(rm_part6->value());
	result9.append("\nTotal cost: ");
	result9.append(to_string(tot_cost));
	result9.append("\n");
	fl_message(result9.c_str());
	rm_dialog->hide();
	
}




void create_partCB(Fl_Window *g, void*)
{	
	
	fstream file("data.csv", ios::in | ios::out | ios::app);
	
	if(file.is_open())
	{
		file << rp_name->value() << " " << rp_number->value() << " " <<"Head" << " " << rp_weight->value() << " " << rp_cost->value() << " " << rp_pow->value() << " " << rp_desc->value() << "\n";
	}
	file.close();
	string result;
	result.append("Head ");
	result.append(rp_name->value());
        result.append(" (Model ");
	result.append(rp_number->value());
	result.append(") costs $");
	result.append(rp_cost->value());
	result.append(" and uses ");
	result.append(rp_pow->value());
	result.append(" watts.\n");
	result.append("Discription: ");
	result.append(rp_desc->value());
	result.append("\n");
	fl_message(result.c_str());


	dialog->hide();
	
	
};


void create_part0CB(Fl_Window *g, void*)
{	
	
	fstream file("datafile.csv", ios::in | ios::out | ios::app);
	
	if(file.is_open())
	{
		file << rp_name->value() << " " << rp_number->value() << " " << rp_type->value() << " " << rp_weight->value() << " " << rp_cost->value() << " " << rp_pow->value() << " " << rp_desc->value() << "\n";
	}
	file.close();
	//file.close();
	string result;
	result.append("Name:         ");
	result.append(rp_name->value());
	result.append("\n");
	result.append("Model Number: ");
	result.append(rp_number->value());
	result.append("\n");
	result.append("Weight:       ");
	result.append(rp_weight->value());
	result.append("\n");
	result.append("Cost:         ");
	result.append(rp_cost->value());
	result.append("\n");
	result.append("Power:        ");
	result.append(rp_pow->value());
	result.append("\n");
	result.append("Discription:  ");
	result.append(rp_desc->value());
	result.append("\n");
	fl_message(result.c_str());


	dialog->hide();
	
	
};




void create_part4CB(Fl_Window *g, void*)
{	
	
		fstream file("datafile1.csv", ios::in | ios::out | ios::app);
	
	if(file.is_open())
	{
		file << rp_name->value() << " " << rp_number->value() << " " << "Arm" << " " << rp_cost->value() << " " << rp_pow->value() << " " << rp_desc->value() << "\n";
	}
	file.close();
	string result;
	result.append("Name: ");
	result.append(rp_name->value());
	result.append("\n");
	result.append("Model Number: ");
	result.append("Name: ");
	fl_message(result.c_str());


	dialog->hide();
	
	
};


void create_part1CB(Fl_Window *g, void*)
{	
	
	fstream file("data.csv", ios::in | ios::out | ios::app);
	
	if(file.is_open())
	{
		file << rp_name->value() << " " << rp_number->value() << " " << "Arm" << " " << rp_cost->value() << " " << rp_pow->value() << " " << rp_desc->value() << "\n";
	}
	file.close();
	string result1;
	result1.append("Arm ");
	result1.append(rp_name->value());
        result1.append(" (Model ");
	result1.append(rp_number->value());
	result1.append(") costs $");
	result1.append(rp_cost->value());
	result1.append(" and uses upto ");
	result1.append(rp_pow->value());
	result1.append(" watts.\n");
	result1.append("Discription: ");
	result1.append(rp_desc->value());
	result1.append("\n");
	fl_message(result1.c_str());


	dialog->hide();
	
	
};

void create_part5CB(Fl_Window *g, void*)
{	
	
	fstream file("data.csv", ios::in | ios::out | ios::app);
	
	if(file.is_open())
	{
		file << rp_name->value() << " " << rp_number->value() << " " << "Torso" << " " << rp_cost->value() << " " << rp_arms->value() << " " << rp_batt->value() << " " << rp_desc->value() << "\n";
	}
	file.close();
	string result5;
	result5.append("Torso ");
	result5.append(rp_name->value());
        result5.append(" (Model ");
	result5.append(rp_number->value());
	result5.append(") costs $");
	result5.append(rp_cost->value());
	result5.append(" and can hold ");
	result5.append(rp_arms->value());
	result5.append(" arms and");
	result5.append(rp_batt->value());
	result5.append(" batteries.\n");
	result5.append("Discription: ");
	result5.append(rp_desc->value());
	result5.append("\n");
	fl_message(result5.c_str());


	dialog->hide();
	
	
};
	

void create_part6CB(Fl_Window *g, void*)
{	
	
	fstream file("data.csv", ios::in | ios::out | ios::app);
	
	if(file.is_open())
	{
		file << rp_name->value() << " " << rp_number->value() << " " << "Locomoter" << " " << rp_cost->value() << " " << rp_pow->value() << " " << rp_desc->value() << "\n";
	}
	file.close();
	string result6;
	result6.append("Locomoter ");
	result6.append(rp_name->value());
        result6.append(" (Model ");
	result6.append(rp_number->value());
	result6.append(") costs $");
	result6.append(rp_cost->value());
	result6.append(" and uses upto ");
	result6.append(rp_pow->value());
	result6.append(" watts.\n");
	result6.append("Discription: ");
	result6.append(rp_desc->value());
	result6.append("\n");
	fl_message(result6.c_str());


	dialog->hide();
	
	
};

void create_part7CB(Fl_Window *g, void*)
{	
	
	fstream file("data.csv", ios::in | ios::out | ios::app);
	
	if(file.is_open())
	{
		file << rp_name->value() << " " << rp_number->value() << " " << "Battery" << " " << rp_cost->value() << " " << rp_ener->value() << " " << rp_pow->value() << " " << rp_desc->value() << "\n";
	}
	file.close();
	string result7;
	result7.append("Battery ");
	result7.append(rp_name->value());
        result7.append(" (Model ");
	result7.append(rp_number->value());
	result7.append(") costs $");
	result7.append(rp_cost->value());
	result7.append(", driving ");
	result7.append(rp_pow->value());
	result7.append(" watts and containing ");
	result7.append(rp_ener->value());
	result7.append("  kWh.\n");
	result7.append("Discription: ");
	result7.append(rp_desc->value());
	result7.append("\n");
	fl_message(result7.c_str());


	dialog->hide();
	
	
};



void Button_SA(Fl_Widget *win, void*)
{
	Fl_Window *sa_win = new Fl_Window(250, 250, "RRS --- Sales Associate:");
	
	Fl_Button *odr = new Fl_Button(50,90,150,40,"Order Robot Model");
	Fl_Button *bill = new Fl_Button(50,150,150,40,"Bill of Sale");
	
	
	sa_win->end();

	odr->callback((Fl_Callback*) Button_Order);
	bill->callback((Fl_Callback*) Button_Bill);
	sa_win->show();

};


void Button_Order(Fl_Widget *sa_win, void*)
{
		order_dialog = new Fl_Window(500,300,"Create Robot Model");
	
		rm_name = new Fl_Input(150, 10, 210, 25, "Order Number: ");
		rm_name->align(FL_ALIGN_LEFT);
		rm_number = new Fl_Input(150, 40, 210, 25, "Model Name: ");
		rm_number->align(FL_ALIGN_LEFT);
		rm_part1 = new Fl_Input(150, 70, 210, 25, "Model Number: ");
		rm_part1->align(FL_ALIGN_LEFT);
		rm_part2 = new Fl_Input(150, 100, 210, 25, "Customer Name: ");
		rm_part2->align(FL_ALIGN_LEFT);
		rm_part3 = new Fl_Input(150, 130, 210, 25, "Date (MMDDYY): ");
		rm_part3->align(FL_ALIGN_LEFT);				
		Fl_Button *order_create = new Fl_Button(245, 230, 120, 25, "Order!");
		order_create->callback((Fl_Callback*) order_modelCB,0);
		
		order_dialog->end();
		order_dialog->show();

};

void order_modelCB(Fl_Widget *w, void*)
{
	fstream file4("order.csv", ios::in | ios::out | ios::app);
	
	if(file4.is_open())
	{
		file4 << rm_name->value() << " " << rm_number->value() << " " << rm_part1->value() << " " << rm_part2->value() << " " << rm_part3->value() << "\n";
	}
	file4.close();
	string result9;
	result9.append("Order Number:  ");
	result9.append(rm_name->value());
	result9.append("\n");
	result9.append("Model Name:    ");
	result9.append(rm_number->value());
	result9.append("\n");
	result9.append("Model Number:   ");
	result9.append(rm_part1->value());
	result9.append("\n");
	result9.append("Customer Name:  ");
	result9.append(rm_part2->value());
	result9.append("\n");
	result9.append("Date(MM/DD/YY): ");
	result9.append(rm_part3->value());
	result9.append("\n");	
	fl_message(result9.c_str());

	order_dialog->hide();
	
}

void Button_Bill(Fl_Window *sa_win, void*)
{
	fstream file("models.csv", ios::in | ios::out | ios::app);
	fstream file2("order.csv", ios::in | ios:: out | ios::app);
	
	Fl_Window *bill = new Fl_Window(800,600, "Bill Of Sale");
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20,20,760,560, "Bill of Sale");
	disp->buffer(buff);	
	bill->resizable(*disp);
	bill->show();	

	string model_name, name, number, onumber, cost, cname, date, mnum;
	string part1, part2, part3, part4, part5, part6, streeng;
	double tot_sale=0.0;
	
	streeng = "OrderNumber\tModelName\tPrice\tCustomer\tDate\n";

	while(file2 >> onumber >> model_name >> mnum >> cname >> date)
	{
		while(file >> name >> number >> cost >> part1 >> part2 >> part3 >> part4 >> part5 >> part6 )
		{		
			if(name == model_name)
			{			
			int money = (int) atoi(cost.c_str());
			tot_sale += money;
			streeng = streeng+ onumber+ "\t\t" + model_name+ "\t\t" + cost+ "\t" + cname+ "\t\t" + date + "\n";
			const char *c = streeng.c_str();
			buff->text(c);
			}
		}
	}
	file.close();
	file2.close();
};

void Button_BC(Fl_Widget *win, void*)
{	
	Fl_Window *bc_win = new Fl_Window(300, 300, "RRS --- Beloved Customer:");
	
	Fl_Button *browse = new Fl_Button(60,70,180,50,"Browse Robot Catalog");
	Fl_Button *cbill = new Fl_Button(60,140,180,50,"View my Bill");
	
	bc_win->end();

	browse->callback((Fl_Callback*) Button_Browse);
	cbill->callback((Fl_Callback*) Button_Bill);
	bc_win->show();

};



void Button_Browse(Fl_Window *bc_win, void*)
{         
        brow = new Fl_Window(800,600,"Browse Catalog");
	fl_register_images();

        Fl_JPEG_Image *robot1 = new Fl_JPEG_Image("robot5.jpg");	
        box1 = new Fl_Box(150,30,100,100);
        box1->image(robot1);
        
        Fl_JPEG_Image *robot2 = new Fl_JPEG_Image("robot4.jpg");	
        box2 = new Fl_Box(150,180,100,100);
        box2->image(robot2);

        Fl_JPEG_Image *robot3 = new Fl_JPEG_Image("robot3.jpg");	
        box3 = new Fl_Box(150,330,100,100);
        box3->image(robot3);

        Fl_JPEG_Image *robot4 = new Fl_JPEG_Image("robot2.jpg");	
        box4 = new Fl_Box(150,480,100,100);
        box4->image(robot4);
        
        Fl_JPEG_Image *robot5 = new Fl_JPEG_Image("robot7.jpg");	
        box5 = new Fl_Box(500,30,100,100);
        box5->image(robot5);
        
        Fl_JPEG_Image *robot6 = new Fl_JPEG_Image("robot1.jpg");	
        box6 = new Fl_Box(500,180,100,100);
        box6->image(robot6);

        Fl_JPEG_Image *robot7 = new Fl_JPEG_Image("robot6.jpg");	
        box7 = new Fl_Box(500,330,100,100);
        box7->image(robot7);

        Fl_JPEG_Image *robot8 = new Fl_JPEG_Image("robot8.jpg");	
        box8 = new Fl_Box(500,480,100,100);
        box8->image(robot8);
        
brow->end();
brow->show();

	
	
};

void Button_PB(Fl_Widget *win, void*)
{
	Fl_Window *boss_win = new Fl_Window(300, 300, "RRS --- Boss");
	
	Fl_Button *sales = new Fl_Button(60,150,180,50,"Sales Report");
	
	boss_win->end();

	sales->callback((Fl_Callback*) Button_Bill);
	boss_win->show();
};


//MAIN FUNCTION
int main()
{
	fl_register_images(); 

	Fl_Box box(15,15,800,600);	
	Fl_JPEG_Image jpg("Backgraound.jpg");
	box.image(jpg);
	Fl_Button *pm = new Fl_Button(150,350,200,30,"Product Manager");
	Fl_Button *sa = new Fl_Button(150,390,200,30,"Sales Associate");
	Fl_Button *bc = new Fl_Button(150,430,200,30,"Customer");
	Fl_Button *pb = new Fl_Button(150,470,200,30,"Boss");
	Fl_Button *xx = new Fl_Button(150,510,200,30,"Exit");

	win.end();



	pm->callback((Fl_Callback*) Button_PM);
	sa->callback((Fl_Callback*) Button_SA);
	bc->callback((Fl_Callback*) Button_BC);
	pb->callback((Fl_Callback*) Button_PB);
	xx->callback((Fl_Callback*) Button_RPart2);

	win.show();

	return Fl::run();
}
