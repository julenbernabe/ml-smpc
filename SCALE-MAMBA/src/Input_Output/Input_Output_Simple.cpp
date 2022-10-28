/*
Copyright (c) 2017, The University of Bristol, Senate House, Tyndall Avenue, Bristol, BS8 1TH, United Kingdom.
Copyright (c) 2021, COSIC-KU Leuven, Kasteelpark Arenberg 10, bus 2452, B-3001 Leuven-Heverlee, Belgium.

All rights reserved
*/

#include "Input_Output_Simple.h"
#include "../Exceptions/Exceptions.h"
#include "../Tools/FormatIO.h"

Input_Output_Simple::Input_Output_Simple() : Input_Output_Base()
{
  nLines= NULL;

  numColumnsIn= 1;

  sRow= "";
  iColumn= 0;

  vOutput= new vector<int>;
}

Input_Output_Simple::~Input_Output_Simple()
{
  delete vOutput;
}

void Input_Output_Simple::init(int playerIndex, int playerCount, string outPath, string shareInPath, string shareOutPath, bool human_type)
{
  // Initialize default formatter for this player
  FormatIO::GetInstance(playerIndex, playerCount);

  // Cannot use standard output, as it spits out a lot of information
  // fout.open(outPath, ios_base::app);
  fout.open(outPath, ios_base::out | ios_base::trunc);
  fsharein.open(shareInPath);
  fshareout.open(shareOutPath);

  human= human_type;
}

void Input_Output_Simple::init(int playerIndex, int playerCount, string inPath, string outPath, string shareInPath, string shareOutPath, bool human_type)
{
  // Initialize default formatter for this player
  FormatIO::GetInstance(playerIndex, playerCount);

  nLines= new uint(count_lines(inPath));

  fin.open(inPath);
  // fout.open(outPath, ios_base::app);
  fout.open(outPath, ios_base::out | ios_base::trunc);
  fsharein.open(shareInPath);
  fshareout.open(shareOutPath);

  human= human_type;
}

uint Input_Output_Simple::count_lines(const string &filePath)
{
  uint lineCount= 0;

  ifstream fin;
  fin.open(filePath);

  string line;
  while (getline(fin, line))
    {
      if (!line.empty())
        {
          lineCount++;
        }
    }

  fin.close();

  return lineCount;
}

bool Input_Output_Simple::read_in(string &line)
{
  if (fin.is_open())
    {
      if (!getline(fin, line))
        {
          return false;
        }
      return true;
    }

  if (!getline(cin, line))
    {
      return false;
    }
  return true;
}

long Input_Output_Simple::open_channel(unsigned int channel)
{
  cout << "Opening channel " << channel << endl;
  return 0;
}

void Input_Output_Simple::close_channel(unsigned int channel)
{
  cout << "Closing channel " << channel << endl;
}

gfp Input_Output_Simple::private_input_gfp(unsigned int channel)
{
  int x= 0;
  string line;
  numColumnsIn = 1;
  if (!read_in(line))
    {
      // End of file: Return 0
      // TODO: Look for other alternative
      x= 0;
      return x;
    }
  sRow= line;
  iColumn= 0;
  x= stoi(line);
  return x;
}

void Input_Output_Simple::private_output_gfp(const gfp &output, unsigned int channel)
{
  cout << "Output channel " << channel << " : ";
  output.output(cout, true);
  cout << endl;
}

gfp Input_Output_Simple::public_input_gfp(unsigned int channel)
{
  cout << "Enter value on channel " << channel << " : ";
  word x;
  cin >> x;
  gfp y;
  y.assign(x);

  // Important to have this call in each version of public_input_gfp
  Update_Checker(y, channel);

  return y;
}

void Input_Output_Simple::public_output_gfp(const gfp &output, unsigned int channel)
{
  cout << "Output channel " << channel << " : ";
  output.output(cout, true);
  cout << endl;
}

long Input_Output_Simple::public_input_int(unsigned int channel)
{
  cout << "Enter value on channel " << channel << " : ";
  long x;
  cin >> x;

  // Important to have this call in each version of public_input_gfp
  Update_Checker(x, channel);

  return x;
}

void Input_Output_Simple::public_output_int(const long output, unsigned int channel)
{
  cout << "Output channel " << channel << " : " << output;
  cout << " = 0x" << hex << output << dec << endl;
}

void Input_Output_Simple::output_share(const Share &S, unsigned int channel)
{
  (*outf) << "Output channel " << channel << " : ";
  S.output(*outf, human);
}

Share Input_Output_Simple::input_share(unsigned int channel)
{
  cout << "Enter value on channel " << channel << " : ";
  Share S;
  S.input(*inpf, human);
  return S;
}

void Input_Output_Simple::trigger(Schedule &schedule)
{
  printf("Restart requested: Enter a number to proceed\n");
  int i;
  cin >> i;

  // Load new schedule file program streams, using the original
  // program name
  //
  // Here you could define programatically what the new
  // programs you want to run are, by directly editing the
  // public variables in the schedule object.
  unsigned int nthreads= schedule.Load_Programs();
  if (schedule.max_n_threads() < nthreads)
    {
      throw Processor_Error("Restart requires more threads, cannot do this");
    }
}

void Input_Output_Simple::debug_output(const stringstream &ss)
{
  printf("%s", ss.str().c_str());
  fflush(stdout);
}

void Input_Output_Simple::crash(unsigned int PC, unsigned int thread_num)
{
  printf("Crashing in thread %d at PC value %d\n", thread_num, PC);
  throw crash_requested();
}
