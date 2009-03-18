namespace DotNetTestApp
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
			this.button_SaveTables = new System.Windows.Forms.Button();
			this.button_LoadTable = new System.Windows.Forms.Button();
			this.fontDialog1 = new System.Windows.Forms.FontDialog();
			this.button_Options = new System.Windows.Forms.Button();
			this.panel_Buttons = new System.Windows.Forms.Panel();
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.radioButton_CustomLanguage = new System.Windows.Forms.RadioButton();
			this.radioButton_Telugu = new System.Windows.Forms.RadioButton();
			this.radioButton_Tamil = new System.Windows.Forms.RadioButton();
			this.radioButton_Sanskrit = new System.Windows.Forms.RadioButton();
			this.radioButton_Malayalam = new System.Windows.Forms.RadioButton();
			this.radioButton_Punjabi = new System.Windows.Forms.RadioButton();
			this.radioButton_Kannada = new System.Windows.Forms.RadioButton();
			this.radioButton_Oriya = new System.Windows.Forms.RadioButton();
			this.radioButton_Hindi = new System.Windows.Forms.RadioButton();
			this.radioButton_Gujarati = new System.Windows.Forms.RadioButton();
			this.radioButton_Bengali = new System.Windows.Forms.RadioButton();
			this.button_Translate = new System.Windows.Forms.Button();
			this.propertyGrid1 = new System.Windows.Forms.PropertyGrid();
			this.textBox_Output = new System.Windows.Forms.TextBox();
			this.panel1 = new System.Windows.Forms.Panel();
			this.splitContainer1 = new System.Windows.Forms.SplitContainer();
			this.textBox_Input = new System.Windows.Forms.TextBox();
			this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
			this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
			this.panel_Buttons.SuspendLayout();
			this.groupBox1.SuspendLayout();
			this.panel1.SuspendLayout();
			this.splitContainer1.Panel1.SuspendLayout();
			this.splitContainer1.Panel2.SuspendLayout();
			this.splitContainer1.SuspendLayout();
			this.SuspendLayout();
			// 
			// button_SaveTables
			// 
			this.button_SaveTables.Location = new System.Drawing.Point(5, 386);
			this.button_SaveTables.Name = "button_SaveTables";
			this.button_SaveTables.Size = new System.Drawing.Size(180, 38);
			this.button_SaveTables.TabIndex = 13;
			this.button_SaveTables.Text = "Save &Phonetic Tables";
			this.button_SaveTables.UseVisualStyleBackColor = true;
			this.button_SaveTables.Click += new System.EventHandler(this.buttonSaveTables_Click);
			// 
			// button_LoadTable
			// 
			this.button_LoadTable.Location = new System.Drawing.Point(5, 430);
			this.button_LoadTable.Name = "button_LoadTable";
			this.button_LoadTable.Size = new System.Drawing.Size(180, 38);
			this.button_LoadTable.TabIndex = 14;
			this.button_LoadTable.Text = "&Load Phonetic Tables";
			this.button_LoadTable.UseVisualStyleBackColor = true;
			this.button_LoadTable.Click += new System.EventHandler(this.buttonLoadTable_Click);
			// 
			// button_Options
			// 
			this.button_Options.Location = new System.Drawing.Point(5, 7);
			this.button_Options.Name = "button_Options";
			this.button_Options.Size = new System.Drawing.Size(180, 38);
			this.button_Options.TabIndex = 16;
			this.button_Options.Text = "<< &Font Options";
			this.button_Options.UseVisualStyleBackColor = true;
			this.button_Options.Click += new System.EventHandler(this.button_Options_Click);
			// 
			// panel_Buttons
			// 
			this.panel_Buttons.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
			this.panel_Buttons.Controls.Add(this.groupBox1);
			this.panel_Buttons.Controls.Add(this.button_SaveTables);
			this.panel_Buttons.Controls.Add(this.button_Translate);
			this.panel_Buttons.Controls.Add(this.button_LoadTable);
			this.panel_Buttons.Controls.Add(this.button_Options);
			this.panel_Buttons.Dock = System.Windows.Forms.DockStyle.Right;
			this.panel_Buttons.Location = new System.Drawing.Point(665, 0);
			this.panel_Buttons.Name = "panel_Buttons";
			this.panel_Buttons.Size = new System.Drawing.Size(186, 480);
			this.panel_Buttons.TabIndex = 6;
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.radioButton_CustomLanguage);
			this.groupBox1.Controls.Add(this.radioButton_Telugu);
			this.groupBox1.Controls.Add(this.radioButton_Tamil);
			this.groupBox1.Controls.Add(this.radioButton_Sanskrit);
			this.groupBox1.Controls.Add(this.radioButton_Malayalam);
			this.groupBox1.Controls.Add(this.radioButton_Punjabi);
			this.groupBox1.Controls.Add(this.radioButton_Kannada);
			this.groupBox1.Controls.Add(this.radioButton_Oriya);
			this.groupBox1.Controls.Add(this.radioButton_Hindi);
			this.groupBox1.Controls.Add(this.radioButton_Gujarati);
			this.groupBox1.Controls.Add(this.radioButton_Bengali);
			this.groupBox1.Location = new System.Drawing.Point(3, 49);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(180, 324);
			this.groupBox1.TabIndex = 19;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "Language";
			// 
			// radioButton_CustomLanguage
			// 
			this.radioButton_CustomLanguage.AutoSize = true;
			this.radioButton_CustomLanguage.Location = new System.Drawing.Point(6, 294);
			this.radioButton_CustomLanguage.Name = "radioButton_CustomLanguage";
			this.radioButton_CustomLanguage.Size = new System.Drawing.Size(141, 21);
			this.radioButton_CustomLanguage.TabIndex = 12;
			this.radioButton_CustomLanguage.Text = "Custom Language";
			this.radioButton_CustomLanguage.UseVisualStyleBackColor = true;
			this.radioButton_CustomLanguage.CheckedChanged += new System.EventHandler(this.radioButton_CustomLanguage_CheckedChanged);
			// 
			// radioButton_Telugu
			// 
			this.radioButton_Telugu.AutoSize = true;
			this.radioButton_Telugu.Location = new System.Drawing.Point(6, 265);
			this.radioButton_Telugu.Name = "radioButton_Telugu";
			this.radioButton_Telugu.Size = new System.Drawing.Size(70, 21);
			this.radioButton_Telugu.TabIndex = 11;
			this.radioButton_Telugu.Text = "Telugu";
			this.radioButton_Telugu.UseVisualStyleBackColor = true;
			this.radioButton_Telugu.CheckedChanged += new System.EventHandler(this.radioButton_Telugu_CheckedChanged);
			// 
			// radioButton_Tamil
			// 
			this.radioButton_Tamil.AutoSize = true;
			this.radioButton_Tamil.Location = new System.Drawing.Point(6, 238);
			this.radioButton_Tamil.Name = "radioButton_Tamil";
			this.radioButton_Tamil.Size = new System.Drawing.Size(60, 21);
			this.radioButton_Tamil.TabIndex = 10;
			this.radioButton_Tamil.Text = "Tamil";
			this.radioButton_Tamil.UseVisualStyleBackColor = true;
			this.radioButton_Tamil.CheckedChanged += new System.EventHandler(this.radioButton_Tamil_CheckedChanged);
			// 
			// radioButton_Sanskrit
			// 
			this.radioButton_Sanskrit.AutoSize = true;
			this.radioButton_Sanskrit.Location = new System.Drawing.Point(6, 211);
			this.radioButton_Sanskrit.Name = "radioButton_Sanskrit";
			this.radioButton_Sanskrit.Size = new System.Drawing.Size(77, 21);
			this.radioButton_Sanskrit.TabIndex = 9;
			this.radioButton_Sanskrit.Text = "Sanskrit";
			this.radioButton_Sanskrit.UseVisualStyleBackColor = true;
			this.radioButton_Sanskrit.CheckedChanged += new System.EventHandler(this.radioButton_Sanskrit_CheckedChanged);
			// 
			// radioButton_Malayalam
			// 
			this.radioButton_Malayalam.AutoSize = true;
			this.radioButton_Malayalam.Location = new System.Drawing.Point(6, 130);
			this.radioButton_Malayalam.Name = "radioButton_Malayalam";
			this.radioButton_Malayalam.Size = new System.Drawing.Size(93, 21);
			this.radioButton_Malayalam.TabIndex = 6;
			this.radioButton_Malayalam.Text = "Malayalam";
			this.radioButton_Malayalam.UseVisualStyleBackColor = true;
			this.radioButton_Malayalam.CheckedChanged += new System.EventHandler(this.radioButton_Malayalam_CheckedChanged);
			// 
			// radioButton_Punjabi
			// 
			this.radioButton_Punjabi.AutoSize = true;
			this.radioButton_Punjabi.Location = new System.Drawing.Point(6, 184);
			this.radioButton_Punjabi.Name = "radioButton_Punjabi";
			this.radioButton_Punjabi.Size = new System.Drawing.Size(73, 21);
			this.radioButton_Punjabi.TabIndex = 8;
			this.radioButton_Punjabi.Text = "Punjabi";
			this.radioButton_Punjabi.UseVisualStyleBackColor = true;
			this.radioButton_Punjabi.CheckedChanged += new System.EventHandler(this.radioButton_Punjabi_CheckedChanged);
			// 
			// radioButton_Kannada
			// 
			this.radioButton_Kannada.AutoSize = true;
			this.radioButton_Kannada.Location = new System.Drawing.Point(6, 103);
			this.radioButton_Kannada.Name = "radioButton_Kannada";
			this.radioButton_Kannada.Size = new System.Drawing.Size(83, 21);
			this.radioButton_Kannada.TabIndex = 5;
			this.radioButton_Kannada.Text = "Kannada";
			this.radioButton_Kannada.UseVisualStyleBackColor = true;
			this.radioButton_Kannada.CheckedChanged += new System.EventHandler(this.radioButton_Kannada_CheckedChanged);
			// 
			// radioButton_Oriya
			// 
			this.radioButton_Oriya.AutoSize = true;
			this.radioButton_Oriya.Location = new System.Drawing.Point(6, 157);
			this.radioButton_Oriya.Name = "radioButton_Oriya";
			this.radioButton_Oriya.Size = new System.Drawing.Size(60, 21);
			this.radioButton_Oriya.TabIndex = 7;
			this.radioButton_Oriya.Text = "Oriya";
			this.radioButton_Oriya.UseVisualStyleBackColor = true;
			this.radioButton_Oriya.CheckedChanged += new System.EventHandler(this.radioButton_Oriya_CheckedChanged);
			// 
			// radioButton_Hindi
			// 
			this.radioButton_Hindi.AutoSize = true;
			this.radioButton_Hindi.Location = new System.Drawing.Point(6, 76);
			this.radioButton_Hindi.Name = "radioButton_Hindi";
			this.radioButton_Hindi.Size = new System.Drawing.Size(58, 21);
			this.radioButton_Hindi.TabIndex = 4;
			this.radioButton_Hindi.Text = "Hindi";
			this.radioButton_Hindi.UseVisualStyleBackColor = true;
			this.radioButton_Hindi.CheckedChanged += new System.EventHandler(this.radioButton_Hindi_CheckedChanged);
			// 
			// radioButton_Gujarati
			// 
			this.radioButton_Gujarati.AutoSize = true;
			this.radioButton_Gujarati.Location = new System.Drawing.Point(6, 48);
			this.radioButton_Gujarati.Name = "radioButton_Gujarati";
			this.radioButton_Gujarati.Size = new System.Drawing.Size(76, 21);
			this.radioButton_Gujarati.TabIndex = 3;
			this.radioButton_Gujarati.Text = "Gujarati";
			this.radioButton_Gujarati.UseVisualStyleBackColor = true;
			this.radioButton_Gujarati.CheckedChanged += new System.EventHandler(this.radioButton_Gujarati_CheckedChanged);
			// 
			// radioButton_Bengali
			// 
			this.radioButton_Bengali.AutoSize = true;
			this.radioButton_Bengali.Location = new System.Drawing.Point(6, 21);
			this.radioButton_Bengali.Name = "radioButton_Bengali";
			this.radioButton_Bengali.Size = new System.Drawing.Size(73, 21);
			this.radioButton_Bengali.TabIndex = 2;
			this.radioButton_Bengali.Text = "Bengali";
			this.radioButton_Bengali.UseVisualStyleBackColor = true;
			this.radioButton_Bengali.CheckedChanged += new System.EventHandler(this.radioButton_Bengali_CheckedChanged);
			// 
			// button_Translate
			// 
			this.button_Translate.Location = new System.Drawing.Point(5, 476);
			this.button_Translate.Name = "button_Translate";
			this.button_Translate.Size = new System.Drawing.Size(180, 38);
			this.button_Translate.TabIndex = 1;
			this.button_Translate.Text = "&Translate";
			this.button_Translate.UseVisualStyleBackColor = true;
			this.button_Translate.Visible = false;
			this.button_Translate.Click += new System.EventHandler(this.button_Translate_Click);
			// 
			// propertyGrid1
			// 
			this.propertyGrid1.Dock = System.Windows.Forms.DockStyle.Right;
			this.propertyGrid1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.propertyGrid1.Location = new System.Drawing.Point(311, 0);
			this.propertyGrid1.Margin = new System.Windows.Forms.Padding(4);
			this.propertyGrid1.Name = "propertyGrid1";
			this.propertyGrid1.SelectedObject = this.textBox_Output;
			this.propertyGrid1.Size = new System.Drawing.Size(354, 480);
			this.propertyGrid1.TabIndex = 19;
			this.propertyGrid1.TabStop = false;
			// 
			// textBox_Output
			// 
			this.textBox_Output.Dock = System.Windows.Forms.DockStyle.Fill;
			this.textBox_Output.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.textBox_Output.Location = new System.Drawing.Point(0, 0);
			this.textBox_Output.Margin = new System.Windows.Forms.Padding(4);
			this.textBox_Output.Multiline = true;
			this.textBox_Output.Name = "textBox_Output";
			this.textBox_Output.ScrollBars = System.Windows.Forms.ScrollBars.Both;
			this.textBox_Output.Size = new System.Drawing.Size(311, 375);
			this.textBox_Output.TabIndex = 17;
			// 
			// panel1
			// 
			this.panel1.Controls.Add(this.splitContainer1);
			this.panel1.Controls.Add(this.propertyGrid1);
			this.panel1.Controls.Add(this.panel_Buttons);
			this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
			this.panel1.Location = new System.Drawing.Point(4, 8);
			this.panel1.Name = "panel1";
			this.panel1.Size = new System.Drawing.Size(851, 480);
			this.panel1.TabIndex = 8;
			// 
			// splitContainer1
			// 
			this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
			this.splitContainer1.Location = new System.Drawing.Point(0, 0);
			this.splitContainer1.Name = "splitContainer1";
			this.splitContainer1.Orientation = System.Windows.Forms.Orientation.Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this.splitContainer1.Panel1.Controls.Add(this.textBox_Output);
			// 
			// splitContainer1.Panel2
			// 
			this.splitContainer1.Panel2.Controls.Add(this.textBox_Input);
			this.splitContainer1.Size = new System.Drawing.Size(311, 480);
			this.splitContainer1.SplitterDistance = 375;
			this.splitContainer1.TabIndex = 0;
			this.splitContainer1.TabStop = false;
			// 
			// textBox_Input
			// 
			this.textBox_Input.Dock = System.Windows.Forms.DockStyle.Fill;
			this.textBox_Input.HideSelection = false;
			this.textBox_Input.Location = new System.Drawing.Point(0, 0);
			this.textBox_Input.Multiline = true;
			this.textBox_Input.Name = "textBox_Input";
			this.textBox_Input.ScrollBars = System.Windows.Forms.ScrollBars.Both;
			this.textBox_Input.Size = new System.Drawing.Size(311, 101);
			this.textBox_Input.TabIndex = 1;
			this.textBox_Input.TextChanged += new System.EventHandler(this.textBox_Input_TextChanged);
			// 
			// saveFileDialog1
			// 
			this.saveFileDialog1.DefaultExt = "PhTable";
			this.saveFileDialog1.FileName = "MyPhoneticTable.PhTable";
			this.saveFileDialog1.Filter = "PhoneticTable Files|*.PhTable|All Files|*.*";
			this.saveFileDialog1.Title = "Save PhoneticTable As";
			// 
			// openFileDialog1
			// 
			this.openFileDialog1.DefaultExt = "PhTable";
			this.openFileDialog1.FileName = "MyPhoneticTable.PhTable";
			this.openFileDialog1.Filter = "PhoneticTable Files|*.PhTable|All Files|*.*";
			this.openFileDialog1.Title = "Select the PhoneticTable";
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(859, 496);
			this.Controls.Add(this.panel1);
			this.Name = "Form1";
			this.Padding = new System.Windows.Forms.Padding(4, 8, 4, 8);
			this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Show;
			this.Text = "Phonetic Translation to Indian Languages";
			this.Load += new System.EventHandler(this.Form1_Load);
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
			this.Resize += new System.EventHandler(this.Form1_Resize);
			this.panel_Buttons.ResumeLayout(false);
			this.groupBox1.ResumeLayout(false);
			this.groupBox1.PerformLayout();
			this.panel1.ResumeLayout(false);
			this.splitContainer1.Panel1.ResumeLayout(false);
			this.splitContainer1.Panel1.PerformLayout();
			this.splitContainer1.Panel2.ResumeLayout(false);
			this.splitContainer1.Panel2.PerformLayout();
			this.splitContainer1.ResumeLayout(false);
			this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button_SaveTables;
		private System.Windows.Forms.Button button_LoadTable;
        private System.Windows.Forms.FontDialog fontDialog1;
        private System.Windows.Forms.Button button_Options;
        private System.Windows.Forms.Panel panel_Buttons;
        private System.Windows.Forms.PropertyGrid propertyGrid1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton radioButton_Bengali;
        private System.Windows.Forms.RadioButton radioButton_Telugu;
        private System.Windows.Forms.RadioButton radioButton_Tamil;
        private System.Windows.Forms.RadioButton radioButton_Sanskrit;
        private System.Windows.Forms.RadioButton radioButton_Malayalam;
        private System.Windows.Forms.RadioButton radioButton_Punjabi;
        private System.Windows.Forms.RadioButton radioButton_Kannada;
        private System.Windows.Forms.RadioButton radioButton_Oriya;
        private System.Windows.Forms.RadioButton radioButton_Hindi;
        private System.Windows.Forms.Button button_Translate;
        private System.Windows.Forms.RadioButton radioButton_CustomLanguage;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.RadioButton radioButton_Gujarati;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.TextBox textBox_Output;
        private System.Windows.Forms.TextBox textBox_Input;
    }
}

