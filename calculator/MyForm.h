#pragma once
#include <string>
#include <cmath>

namespace calcLog {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>

	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: 
			//
		}

	protected:
		/// <summary>
		/// 
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::TextBox^ textBox1;


	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^  In;

	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  arrow2;
	private: System::Windows::Forms::Label^  arrow1;
	private: System::Windows::Forms::Label^  arrow3;
	private: System::Windows::Forms::Label^  arrow4;
	private: System::Windows::Forms::Label^  arrow5;
	private: System::Windows::Forms::Label^  arrow6;
	private: System::Windows::Forms::Button^  btndot;



	protected:

	private:
		/// <summary>
		/// 
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->In = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->arrow2 = (gcnew System::Windows::Forms::Label());
			this->arrow1 = (gcnew System::Windows::Forms::Label());
			this->arrow3 = (gcnew System::Windows::Forms::Label());
			this->arrow4 = (gcnew System::Windows::Forms::Label());
			this->arrow5 = (gcnew System::Windows::Forms::Label());
			this->arrow6 = (gcnew System::Windows::Forms::Label());
			this->btndot = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SeaShell;
			this->button1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button1->Location = System::Drawing::Point(129, 212);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(37, 37);
			this->button1->TabIndex = 0;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::btn1);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::SeaShell;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(129, 176);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(37, 37);
			this->button2->TabIndex = 1;
			this->button2->Text = L"4";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::btn4);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::SeaShell;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(129, 140);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(37, 37);
			this->button3->TabIndex = 2;
			this->button3->Text = L"7";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::btn7);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::SeaShell;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(165, 176);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(37, 37);
			this->button4->TabIndex = 3;
			this->button4->Text = L"5";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::btn5);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::SeaShell;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(201, 212);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(37, 37);
			this->button5->TabIndex = 4;
			this->button5->Text = L"3";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::btn3);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::SeaShell;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(201, 176);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(37, 37);
			this->button6->TabIndex = 5;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::btn6);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::SeaShell;
			this->button7->Cursor = System::Windows::Forms::Cursors::Default;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button7->Location = System::Drawing::Point(165, 212);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(37, 37);
			this->button7->TabIndex = 6;
			this->button7->Text = L"2";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::btn2);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::SeaShell;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(165, 140);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(37, 37);
			this->button8->TabIndex = 7;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::btn8);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::SeaShell;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(201, 140);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(37, 37);
			this->button9->TabIndex = 8;
			this->button9->Text = L"9";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::btn9);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::SeaShell;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10->Location = System::Drawing::Point(129, 248);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(73, 37);
			this->button10->TabIndex = 9;
			this->button10->Text = L"0";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::btn0);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(314, 40);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(102, 20);
			this->textBox1->TabIndex = 10;
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::SeaShell;
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button13->Location = System::Drawing::Point(237, 140);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(37, 37);
			this->button13->TabIndex = 13;
			this->button13->Text = L"/";
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::btndiv);
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::Color::SeaShell;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button14->Location = System::Drawing::Point(237, 176);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(37, 37);
			this->button14->TabIndex = 14;
			this->button14->Text = L"*";
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::btnmulti);
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::Color::SeaShell;
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button15->Location = System::Drawing::Point(237, 212);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(37, 37);
			this->button15->TabIndex = 15;
			this->button15->Text = L"-";
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::btnminus);
			// 
			// button16
			// 
			this->button16->BackColor = System::Drawing::Color::SeaShell;
			this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button16->Location = System::Drawing::Point(237, 248);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(37, 37);
			this->button16->TabIndex = 16;
			this->button16->Text = L"+";
			this->button16->UseVisualStyleBackColor = false;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::btnplus);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(70, 40);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(54, 20);
			this->textBox2->TabIndex = 17;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(233, 40);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(54, 20);
			this->textBox3->TabIndex = 18;
			// 
			// button17
			// 
			this->button17->BackColor = System::Drawing::Color::SeaShell;
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button17->Location = System::Drawing::Point(314, 98);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(102, 29);
			this->button17->TabIndex = 19;
			this->button17->Text = L"Результат";
			this->button17->UseVisualStyleBackColor = false;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::btnresult);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(142, 40);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(20, 20);
			this->textBox4->TabIndex = 20;
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// button18
			// 
			this->button18->BackColor = System::Drawing::Color::SeaShell;
			this->button18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button18->Location = System::Drawing::Point(3, 98);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(102, 30);
			this->button18->TabIndex = 21;
			this->button18->Text = L"Очистить";
			this->button18->UseVisualStyleBackColor = false;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::btnclear);
			// 
			// In
			// 
			this->In->BackColor = System::Drawing::Color::SeaShell;
			this->In->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->In->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->In->Location = System::Drawing::Point(150, 98);
			this->In->Name = L"In";
			this->In->Size = System::Drawing::Size(102, 29);
			this->In->TabIndex = 22;
			this->In->Text = L"Ввод";
			this->In->UseVisualStyleBackColor = false;
			this->In->Click += gcnew System::EventHandler(this, &MyForm::cin);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(44, 54);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(20, 20);
			this->textBox5->TabIndex = 23;
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(208, 55);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(20, 20);
			this->textBox6->TabIndex = 24;
			this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(8, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 20);
			this->label1->TabIndex = 26;
			this->label1->Text = L"Log";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(172, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 20);
			this->label2->TabIndex = 27;
			this->label2->Text = L"Log";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(292, 40);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(18, 20);
			this->label3->TabIndex = 28;
			this->label3->Text = L"=";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(135, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(136, 20);
			this->label4->TabIndex = 29;
			this->label4->Text = L"Введите пример";
			// 
			// arrow2
			// 
			this->arrow2->AutoSize = true;
			this->arrow2->BackColor = System::Drawing::Color::Transparent;
			this->arrow2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->arrow2->Location = System::Drawing::Point(42, 77);
			this->arrow2->Name = L"arrow2";
			this->arrow2->Size = System::Drawing::Size(25, 20);
			this->arrow2->TabIndex = 30;
			this->arrow2->Text = L"↑";
			// 
			// arrow1
			// 
			this->arrow1->AutoSize = true;
			this->arrow1->BackColor = System::Drawing::Color::Transparent;
			this->arrow1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->arrow1->Location = System::Drawing::Point(87, 63);
			this->arrow1->Name = L"arrow1";
			this->arrow1->Size = System::Drawing::Size(25, 20);
			this->arrow1->TabIndex = 31;
			this->arrow1->Text = L"↑";
			// 
			// arrow3
			// 
			this->arrow3->AutoSize = true;
			this->arrow3->BackColor = System::Drawing::Color::Transparent;
			this->arrow3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->arrow3->Location = System::Drawing::Point(141, 63);
			this->arrow3->Name = L"arrow3";
			this->arrow3->Size = System::Drawing::Size(25, 20);
			this->arrow3->TabIndex = 32;
			this->arrow3->Text = L"↑";
			// 
			// arrow4
			// 
			this->arrow4->AutoSize = true;
			this->arrow4->BackColor = System::Drawing::Color::Transparent;
			this->arrow4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->arrow4->Location = System::Drawing::Point(250, 63);
			this->arrow4->Name = L"arrow4";
			this->arrow4->Size = System::Drawing::Size(25, 20);
			this->arrow4->TabIndex = 33;
			this->arrow4->Text = L"↑";
			// 
			// arrow5
			// 
			this->arrow5->AutoSize = true;
			this->arrow5->BackColor = System::Drawing::Color::Transparent;
			this->arrow5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->arrow5->Location = System::Drawing::Point(206, 77);
			this->arrow5->Name = L"arrow5";
			this->arrow5->Size = System::Drawing::Size(25, 20);
			this->arrow5->TabIndex = 34;
			this->arrow5->Text = L"↑";
			// 
			// arrow6
			// 
			this->arrow6->AutoSize = true;
			this->arrow6->BackColor = System::Drawing::Color::Transparent;
			this->arrow6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->arrow6->Location = System::Drawing::Point(352, 133);
			this->arrow6->Name = L"arrow6";
			this->arrow6->Size = System::Drawing::Size(25, 20);
			this->arrow6->TabIndex = 35;
			this->arrow6->Text = L"↑";
			// 
			// btndot
			// 
			this->btndot->BackColor = System::Drawing::Color::SeaShell;
			this->btndot->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btndot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btndot->Location = System::Drawing::Point(201, 248);
			this->btndot->Name = L"btndot";
			this->btndot->Size = System::Drawing::Size(37, 37);
			this->btndot->TabIndex = 36;
			this->btndot->Text = L",";
			this->btndot->UseVisualStyleBackColor = false;
			this->btndot->Click += gcnew System::EventHandler(this, &MyForm::btndot_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(419, 287);
			this->Controls->Add(this->btndot);
			this->Controls->Add(this->arrow6);
			this->Controls->Add(this->arrow5);
			this->Controls->Add(this->arrow4);
			this->Controls->Add(this->arrow3);
			this->Controls->Add(this->arrow1);
			this->Controls->Add(this->arrow2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->In);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(435, 325);
			this->MinimumSize = System::Drawing::Size(435, 325);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Log-калькулятор";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int stage;
		bool f1 = false, f2 = false, f3 = false, f4 = false;
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		textBox1->Text = "";
		textBox2->Text = "";
		textBox3->Text = "";
		textBox4->Text = "";
		textBox5->Text = "";
		textBox6->Text = "";
		stage = 0;
		arrow1->Visible = true;
		arrow2->Visible = false;
		arrow3->Visible = false;
		arrow4->Visible = false;
		arrow5->Visible = false;
		arrow6->Visible = false;
	}
	private: System::Void btnresult(System::Object^ sender, System::EventArgs^ e) {
		double a, b, c, a2, b2;
		a = System::Convert::ToDouble(textBox2->Text);
		a2 = System::Convert::ToDouble(textBox5->Text);
		if (textBox3->Text != "")
			b = System::Convert::ToDouble(textBox3->Text);
		if (textBox6->Text != "")
			b2 = System::Convert::ToDouble(textBox6->Text);
		if (textBox3->Text == "" && textBox6->Text == "" && a > 0 && a2 > 0 && a != 1)
		{
			c = log(a) / log(a2);
		}
		else
		{
			if (textBox4->Text == "+" && textBox2->Text && textBox3->Text)
			{
				if (a2 = b2)
					c = log(a * b) / log(a2);
				else
					c = log(a) / log(a2) + log(b) / log(b2);
			}
			if (textBox4->Text == "-" && textBox2->Text && textBox3->Text)
			{
				if (a2 = b2)
					c = log(a / b) / log(a2);
				else
					c = log(a) / log(a2) - log(b) / log(b2);
			}
			if (textBox4->Text == "*" && textBox2->Text && textBox3->Text)
			{
				if (a2 == b && b2 == a)
					c = 1;
				else
					c = log(a) / log(a2) * log(b) / log(b2);
			}
			if (textBox4->Text == "/" && textBox2->Text && textBox3->Text)
			{
				if (a2 == b2)
					c = log(a) / log(b);
				else
					log(a) / log(a2) / log(b) / log(b2);
			}
		}
		textBox1->Text = System::Convert::ToString(c);
	}
	private: System::Void btnclear(System::Object^ sender, System::EventArgs^ e)
	{
		textBox1->Text = "";
		textBox2->Text = "";
		textBox3->Text = "";
		textBox4->Text = "";
		textBox5->Text = "";
		textBox6->Text = "";
		stage = 0;
		arrow1->Visible = true;
		arrow2->Visible = false;
		arrow3->Visible = false;
		arrow4->Visible = false;
		arrow5->Visible = false;
		arrow6->Visible = false;
	}
	private: System::Void cin(System::Object^ sender, System::EventArgs^ e)
	{
		stage++;
		switch (stage)
		{
		case 1:
			arrow1->Visible = false;
			arrow2->Visible = true;
			break;
		case 2:
			arrow2->Visible = false;
			arrow3->Visible = true;
			break;
		case 3:
			arrow3->Visible = false;
			arrow4->Visible = true;
			break;
		case 4:
			arrow4->Visible = false;
			arrow5->Visible = true;
			break;
		case 5:
			arrow5->Visible = false;
			arrow6->Visible = true;
		}
	}
	private: System::Void btn1(System::Object^ sender, System::EventArgs^ e)
	{
		switch (stage)
		{
		case 0:
			textBox2->Text += System::Convert::ToString(1);
			break;
		case 1:
			textBox5->Text += System::Convert::ToString(1);
			break;
		case 3:
			textBox3->Text += System::Convert::ToString(1);
			break;
		case 4:
			textBox6->Text += System::Convert::ToString(1);
			break;
		}
	}
	private: System::Void btn2(System::Object^ sender, System::EventArgs^ e)
	{
		switch (stage)
		{
		case 0:
			textBox2->Text += System::Convert::ToString(2);
			break;
		case 1:
			textBox5->Text += System::Convert::ToString(2);
			break;
		case 3:
			textBox3->Text += System::Convert::ToString(2);
			break;
		case 4:
			textBox6->Text += System::Convert::ToString(2);
			break;
		}
	}
	private: System::Void btn3(System::Object^ sender, System::EventArgs^ e)
	{
		switch (stage)
		{
		case 0:
			textBox2->Text += System::Convert::ToString(3);
			break;
		case 1:
			textBox5->Text += System::Convert::ToString(3);
			break;
		case 3:
			textBox3->Text += System::Convert::ToString(3);
			break;
		case 4:
			textBox6->Text += System::Convert::ToString(3);
			break;
		}
	}
	private: System::Void btn4(System::Object^ sender, System::EventArgs^ e) {
		switch (stage)
		{
		case 0:
			textBox2->Text += System::Convert::ToString(4);
			break;
		case 1:
			textBox5->Text += System::Convert::ToString(4);
			break;
		case 3:
			textBox3->Text += System::Convert::ToString(4);
			break;
		case 4:
			textBox6->Text += System::Convert::ToString(4);
			break;
		}
	}
	private: System::Void btn5(System::Object^ sender, System::EventArgs^ e) {
		switch (stage)
		{
		case 0:
			textBox2->Text += System::Convert::ToString(5);
			break;
		case 1:
			textBox5->Text += System::Convert::ToString(5);
			break;
		case 3:
			textBox3->Text += System::Convert::ToString(5);
			break;
		case 4:
			textBox6->Text += System::Convert::ToString(5);
			break;
		}
	}
	private: System::Void btn6(System::Object^ sender, System::EventArgs^ e) {
		switch (stage)
		{
		case 0:
			textBox2->Text += System::Convert::ToString(6);
			break;
		case 1:
			textBox5->Text += System::Convert::ToString(6);
			break;
		case 3:
			textBox3->Text += System::Convert::ToString(6);
			break;
		case 4:
			textBox6->Text += System::Convert::ToString(6);
			break;
		}
	}
	private: System::Void btn7(System::Object^ sender, System::EventArgs^ e) {
		switch (stage)
		{
		case 0:
			textBox2->Text += System::Convert::ToString(7);
			break;
		case 1:
			textBox5->Text += System::Convert::ToString(7);
			break;
		case 3:
			textBox3->Text += System::Convert::ToString(7);
			break;
		case 4:
			textBox6->Text += System::Convert::ToString(7);
			break;
		}
	}
	private: System::Void btn8(System::Object^ sender, System::EventArgs^ e) {
		switch (stage)
		{
		case 0:
			textBox2->Text += System::Convert::ToString(8);
			break;
		case 1:
			textBox5->Text += System::Convert::ToString(8);
			break;
		case 3:
			textBox3->Text += System::Convert::ToString(8);
			break;
		case 4:
			textBox6->Text += System::Convert::ToString(8);
			break;
		}
	}
	private: System::Void btn9(System::Object^ sender, System::EventArgs^ e) {
		switch (stage)
		{
		case 0:
			textBox2->Text += System::Convert::ToString(9);
			break;
		case 1:
			textBox5->Text += System::Convert::ToString(9);
			break;
		case 3:
			textBox3->Text += System::Convert::ToString(9);
			break;
		case 4:
			textBox6->Text += System::Convert::ToString(9);
			break;
		}
	}
	private: System::Void btn0(System::Object^ sender, System::EventArgs^ e) {
		switch (stage)
		{
		case 0:
			textBox2->Text += System::Convert::ToString(0);
			break;
		case 1:
			textBox5->Text += System::Convert::ToString(0);
			break;
		case 3:
			textBox3->Text += System::Convert::ToString(0);
			break;
		case 4:
			textBox6->Text += System::Convert::ToString(0);
			break;
		}
	}
	private: System::Void btnplus(System::Object^ sender, System::EventArgs^ e) {
		String^ plus = "+";
		switch (stage)
		{
		case 2:
			textBox4->Text += System::Convert::ToString(plus);
			break;
		}
	}
	private: System::Void btnminus(System::Object^ sender, System::EventArgs^ e) {
		String^ minus = "-";
		switch (stage)
		{
		case 2:
			textBox4->Text += System::Convert::ToString(minus);
			break;
		}
	}
	private: System::Void btnmulti(System::Object^ sender, System::EventArgs^ e) {
		String^ multiply = "*";
		switch (stage)
		{
		case 2:
			textBox4->Text += System::Convert::ToString(multiply);
			break;
		}
	}
	private: System::Void btndiv(System::Object^ sender, System::EventArgs^ e) {
		String^ division = "/";
		switch (stage)
		{
		case 2:
			textBox4->Text += System::Convert::ToString(division);
			break;
		}
	}
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	cin(sender,e);
}
private: System::Void btndot_Click(System::Object^  sender, System::EventArgs^  e) {
	switch (stage)
	{
	case 0:
		if (!f1) {
			if (textBox2->Text != "") {
				textBox2->Text += ",";
				f1 = true;
			}
		}
		break;
	case 1:
		if (!f2) {
			if (textBox5->Text != "") {
				textBox5->Text += ",";
				f2 = true;
			}
		}
		break;
	case 3:
		if (!f3) {
			if (textBox3->Text != "") {
				textBox3->Text += ",";
				f3 = true;
			}
		}
		break;
	case 4:
		if (!f4) {
			if (textBox6->Text != "") {
				textBox6->Text += ",";
				f4 = true;
			}
		}
		break;
	}
}
};
}
