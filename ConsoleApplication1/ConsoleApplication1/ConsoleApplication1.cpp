#include <iostream>
#include <string>
#include <iomanip> 
#include <vector>

using namespace std;

void GPUDisplay() {
	cout << "+------------------------------------------------------------------------------------------+\n";
	cout << "| NVIDIA-SMI 551.86                Driver Version: 555.86           CUDA Version: 12.4     |\n";
	cout << "|----------------------------------------+--------------------------+----------------------|\n";
	cout << "| GPU  Name                    TCC/WDDM  | Bus-Id            Disp.A | Volatile Uncorr. ECC |\n";
	cout << "| Fan  Temp    Perf        Pwr:Usage/Cap |             Memory-Usage | GPU-Util  Compute M. |\n";
	cout << "|                                        |                          |               Mig M. |\n";
	cout << "|========================================+==========================+======================|\n";
	cout << "|   0  NVIDIA GeForce RTX 4060     WDDM  |      00000000:32:00.0 On |                  N/A |\n";
	cout << "| 28%   45C    P8            11W /  180W |        901MiB /  8192MiB |     0%       Default |\n";
	cout << "|                                        |                          |                  N/A |\n";
	cout << "+------------------------------------------------------------------------------------------+\n";
	cout << "\n";

}
vector<vector<string>> getProcess() {
	vector<vector<string>> process = {
	{"0", "1368", "C+G", "C:\\Windows\\System32\\dwm.exe"},
	{"0", "1424", "U-S", "C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe"},
	{"0", "1580", "BKG", "C:\\Windows\\System32\\svchost.exe"},
	{"0", "1892", "SYS", "C:\\Windows\\System32\\csrss.exe"},
	{"0", "2036", "U-I", "C:\\Users\\User\\AppData\\Local\\Discord\\Update.exe"},
	{"0", "2204", "C+G", "C:\\Program Files\\Adobe\\Acrobat DC\\Acrobat\\acrobat.exe"},
	{"0", "2376", "BKG", "C:\\Windows\\System32\\spoolsv.exe"},
	{"0", "2512", "U-S", "C:\\Users\\User\\AppData\\Local\\Spotify\\Spotify.exe"},
	{"0", "2688", "SYS", "C:\\Windows\\System32\\winlogon.exe"},
	{"0", "2840", "U-I", "C:\\Program Files\\Microsoft VS Code\\Code.exe"},

	
	};
	return process;
}
string truncatePath(const string& path, size_t limit) {
	if (path.length() > limit) {
		return "..." + path.substr(path.length() - (limit - 3));
	}
	else {
		return path;
	}
}
void printProcesses() {
	vector<vector<string>> process;
	process = getProcess();
	cout << "|===========================================================================================|\n";
	cout << "| Processes:                                                                                |\n";
	cout << "|  GPU   GI    CI    PID     Type   Process name                                 GPU Memory |\n";
	cout << "|        ID    ID                                                                Usage      |\n";
	cout << "|===========================================================================================|\n";

	for (int i = 0; i < process.size(); ++i) {
		string truncated = truncatePath(process[i][3], 40);
		cout << "|  " << setw(3) << process[i][0] << "  "
			<< setw(4) << "N/A" << "  "
			<< setw(4) << "N/A" << "  "
			<< setw(5) << process[i][1]
			<< "    " << setw(3) << process[i][2]
			<< "    " << left << setw(40) << truncated << right
			<< "      " << "N/A" << "       |\n";
			
	}
	cout << "+-------------------------------------------------------------------------------------------+\n";
}
int main() {
	string inputCommand;

	while (true) {
		cout << "Enter a command: ";
		getline(cin, inputCommand);

		if (inputCommand == "nvidia-smi") {
			GPUDisplay();
			printProcesses();
		}
		else if (inputCommand == "exit") {
			cout << "Exiting the program.\n";
			break;
		}
		else {
			cout << "Unknown command. Try again.\n";
		}
	}
	return 0;
}