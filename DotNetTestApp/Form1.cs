using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace DotNetTestApp
{
    public partial class Form1 : Form
    {
        [DllImport("PhTranslateLib.dll")]
        public static extern IntPtr GetTeluguTranslator();

        [DllImport("PhTranslateLib.dll")]
        public static extern IntPtr GetBengaliTranslator();

        [DllImport("PhTranslateLib.dll")]
        public static extern IntPtr GetGujaratiTranslator();

        [DllImport("PhTranslateLib.dll")]
        public static extern IntPtr GetHindiTranslator();

        [DllImport("PhTranslateLib.dll")]
        public static extern IntPtr GetKannadaTranslator();

        [DllImport("PhTranslateLib.dll")]
        public static extern IntPtr GetMalayalamTranslator();

        [DllImport("PhTranslateLib.dll")]
        public static extern IntPtr GetPunjabiTranslator();

        [DllImport("PhTranslateLib.dll")]
        public static extern IntPtr GetOriyaTranslator();

        [DllImport("PhTranslateLib.dll")]
        public static extern IntPtr GetSanskritTranslator();

        [DllImport("PhTranslateLib.dll")]
        public static extern IntPtr GetTamilTranslator();

        [DllImport("PhTranslateLib.dll")]
        public static extern IntPtr CreateCustomTranslator([MarshalAs(UnmanagedType.LPStr)] String szPhoneticTableFilePath);

        [DllImport("PhTranslateLib.dll")]
        public static extern void ReleaseCustomTranslator(IntPtr Translator);

        [DllImport("PhTranslateLib.dll")]
        public static extern int Translate(IntPtr Translator, [MarshalAs(UnmanagedType.LPStr)] String szInput, [MarshalAs(UnmanagedType.LPWStr)] StringBuilder szOutput, int nLen);
        
        [DllImport("PhTranslateLib.dll")]
        public static extern int TranslateW(IntPtr Translator, [MarshalAs(UnmanagedType.LPWStr)] String szInput, [MarshalAs(UnmanagedType.LPWStr)] StringBuilder szOutput, int nLen);
        
        [DllImport("PhTranslateLib.dll")]
         public static extern int GetTranslatedBufferLength(IntPtr Translator, [MarshalAs(UnmanagedType.LPStr)] String szInput, ref IntPtr ppHint);

        [DllImport("PhTranslateLib.dll")]
         public static extern int GetTranslatedBufferLengthW(IntPtr Translator, [MarshalAs(UnmanagedType.LPWStr)] String szInput, ref IntPtr ppHint);

        [DllImport("PhTranslateLib.dll")]
        public static extern void GetTranslatedBuffer([MarshalAs(UnmanagedType.LPWStr)] StringBuilder szOutput, ref System.IntPtr ppHint);

        [DllImport("PhTranslateLib.dll")]
        public static extern bool SavePhoneticTable(IntPtr Translator, [MarshalAs(UnmanagedType.LPStr)] String szFilePath);

        public Form1()
        {
            InitializeComponent();
        }

        System.IntPtr m_CurrentTranslator = IntPtr.Zero;
        System.IntPtr m_CustomTranslator = IntPtr.Zero;

        private void Form1_Load(object sender, EventArgs e)
        {
            propertyGrid1.Visible = false;

            radioButton_Sanskrit.Checked = true;

            textBox_Input.Text = "swaagatam";
            textBox_Input.SelectAll();
            button_Translate_Click(this, new EventArgs());
        }


        private void button_Options_Click(object sender, EventArgs e)
        {
            if (propertyGrid1.Visible == false)
            {
                this.button_Options.Text = "&Font Options >>";
                propertyGrid1.Visible = true;
            }
            else
            {
                this.button_Options.Text = "<< &Font Options";
                propertyGrid1.Visible = false;
            }
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            //panel1.Size = new Size(this.Width - 2 * panel1.Left, this.Height - 4 * panel1.Top);
            //this.Text = panel1.Size.ToString() + this.DefaultPadding.ToString();
            //this.DefaultPadding

        }

        private void buttonSaveTables_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1.ShowDialog() != DialogResult.OK)
                return;
            SavePhoneticTable(m_CurrentTranslator, saveFileDialog1.FileName);
        }

        private void buttonExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void radioButton_Telugu_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton_Telugu.Checked == true)
            {
                m_CurrentTranslator = GetTeluguTranslator();
                button_Translate_Click(this, new EventArgs());
            }
        }

        private void button_Translate_Click(object sender, EventArgs e)
        {
            String strInput = textBox_Input.Text;

            IntPtr ppHint = System.IntPtr.Zero;
            
            int nLen = GetTranslatedBufferLengthW(m_CurrentTranslator, strInput, ref ppHint);
            StringBuilder strBufferW = new StringBuilder(nLen);
            GetTranslatedBuffer(strBufferW, ref ppHint);

            textBox_Output.Text = strBufferW.ToString();
        }

        private void buttonLoadTable_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {           
                System.IntPtr customTranslator = CreateCustomTranslator(openFileDialog1.FileName);
                if (customTranslator == System.IntPtr.Zero)
                    MessageBox.Show("Load Failed for " + openFileDialog1.FileName);
                else
                {
                    ReleaseCustomTranslator(this.m_CustomTranslator);
                    this.m_CustomTranslator = customTranslator;
                    if (radioButton_CustomLanguage.Checked == true)
                        m_CurrentTranslator = m_CustomTranslator;
                }
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            ReleaseCustomTranslator(this.m_CustomTranslator);
        }

        private void radioButton_CustomLanguage_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton_CustomLanguage.Checked == true)
            {
                if (m_CustomTranslator == IntPtr.Zero)
                {
                    buttonLoadTable_Click(this, new EventArgs());
                    if (m_CustomTranslator == IntPtr.Zero) // if loading failed
                    {
                        MessageBox.Show("CustomTranslation option requires a PhoneticTable to be loaded successfully !!", "PhoneticTable Load Failure", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                        this.radioButton_Sanskrit.Checked = true;
                    }
                }
                else // if CustomTranslator already loaded previously, just set to it
                    m_CurrentTranslator = m_CustomTranslator;

                button_Translate_Click(this, new EventArgs());
            }
        }

        private void radioButton_Bengali_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton_Bengali.Checked == true)
            {
                m_CurrentTranslator = GetBengaliTranslator();
                button_Translate_Click(this, new EventArgs());
            }
        }

        private void radioButton_Sanskrit_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton_Sanskrit.Checked == true)
            {
                m_CurrentTranslator = GetSanskritTranslator();
                button_Translate_Click(this, new EventArgs());
            }
        }

        private void radioButton_Kannada_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton_Kannada.Checked == true)
            {
                m_CurrentTranslator = GetKannadaTranslator();
                button_Translate_Click(this, new EventArgs());
            }
        }

        private void radioButton_Hindi_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton_Hindi.Checked == true)
            {
                m_CurrentTranslator = GetHindiTranslator();
                button_Translate_Click(this, new EventArgs());
            }
        }

        private void radioButton_Malayalam_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton_Malayalam.Checked == true)
            {
                m_CurrentTranslator = GetMalayalamTranslator();
                button_Translate_Click(this, new EventArgs());
            }
        }

        private void radioButton_Oriya_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton_Oriya.Checked == true)
            {
                m_CurrentTranslator = GetOriyaTranslator();
                button_Translate_Click(this, new EventArgs());
            }
        }

        private void radioButton_Gujarati_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton_Gujarati.Checked == true)
            {
                m_CurrentTranslator = GetGujaratiTranslator();
                button_Translate_Click(this, new EventArgs());
            }
        }

        private void radioButton_Tamil_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton_Tamil.Checked == true)
            {
                m_CurrentTranslator = GetTamilTranslator();
                button_Translate_Click(this, new EventArgs());
            }
        }

        private void radioButton_Punjabi_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton_Punjabi.Checked == true)
            {
                m_CurrentTranslator = GetPunjabiTranslator();
                button_Translate_Click(this, new EventArgs());
            }
        }

        private void textBox_Input_TextChanged(object sender, EventArgs e)
        {
            button_Translate_Click(this, new EventArgs());
        }
    }
}
