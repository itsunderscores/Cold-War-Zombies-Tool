#include "Maintwo.h"
#include "bypass.h"


#include <random>

/*
*	Player 1 Booleans
*/
bool Infrared = false;
bool InstaKill = false;
bool infiniteHealth = false;
bool infiniteAmmo = false;
bool infinitePoints = false;
bool alwaysInstaKill = false;
bool alwaysCrit = false;
bool jumpHeight = false;
bool p1Speed = false;
bool zombieTP = false;
bool extraZombiesTP = false;
bool tpAllZombies = false;
bool newZombieLocation = false;
bool playerRankXP = false;
bool playerWeaponXP = false;
bool p1WCycle = false;
bool p1LCycle = false;
bool p1TCycle = false;
bool p1WWCycle = false;
bool p1KSCycle = false;
bool p1FUCycle = false;
bool playerName = false;
bool quickStart = false;
bool skipRounds = false;
bool blaznOneShot = false;
bool gunCycle2 = false;
/*
*	Player 2 booleans
*/
bool p2infiniteHealth = false;
bool p2infiniteAmmo = false;
bool p2infinitePoints = false;
bool p2alwaysCrit = false;
bool p2jumpHeight = false;
bool p2zombieTP = false;
bool p2playerTP = false;
bool p2newZombieLocation = false;
bool p2WCycle = false;
bool p2LCycle = false;
bool p2TCycle = false;
bool p2WWCycle = false;
bool p2KSCycle = false;
bool p2FUCycle = false;
/*
*	Player 3 booleans
*/
bool p3infiniteHealth = false;
bool p3infiniteAmmo = false;
bool p3infinitePoints = false;
bool p3alwaysCrit = false;
bool p3jumpHeight = false;
bool p3zombieTP = false;
bool p3playerTP = false;
bool p3newZombieLocation = false;
bool p3WCycle = false;
bool p3LCycle = false;
bool p3TCycle = false;
bool p3WWCycle = false;
bool p3KSCycle = false;
bool p3FUCycle = false;
/*
*	Player 4 booleans
*/
bool p4infiniteHealth = false;
bool p4infiniteAmmo = false;
bool p4infinitePoints = false;
bool p4alwaysCrit = false;
bool p4jumpHeight = false;
bool p4zombieTP = false;
bool p4playerTP = false;
bool p4newZombieLocation = false;
bool p4WCycle = false;
bool p4LCycle = false;
bool p4TCycle = false;
bool p4WWCycle = false;
bool p4KSCycle = false;
bool p4FUCycle = false;
/*
*	Extra Goodies booleans
*/
bool restartGame = false;
bool disconnectGame = false;
bool publicGame = false;
bool privateGame = false;
bool longRevive = false;
bool freezeBox = false;
bool clientKick1 = false;
float xpval = 0.f;

string keyInput;
DWORD oofBoiii;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets)
{
	uintptr_t addr = ptr;
	for (unsigned int i = 0; i < offsets.size(); ++i)
	{
		ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
		addr += offsets[i];
	}
	return addr;
}


void axeraMenuBody()
{


	Sleep(1000);

	////////////////////////////////////////														////////////////////////////////////////
	////////////////////									Main Program Function										////////////////////
	////////////////////////////////////////														////////////////////////////////////////
	unique_ptr<DriverManager> driver = std::make_unique<DriverManager>("\\\\.\\NTIOLib_MB");

	while (!driver->GetProcessID("BlackOpsColdWar.exe"))
	{
		system("cls");
		cout << "[+] :Launch The Game First" << endl << endl;
		cout << "[+] : Exiting....";
		this_thread::sleep_for(std::chrono::seconds(5));
		system("cls");
		exit(0);
	}

	system("cls");
	this_thread::sleep_for(std::chrono::seconds(1));

	HWND console2 = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console2, &ConsoleRect);
	ShowWindow(console2, FALSE);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Overlay::Loop, nullptr, 0, nullptr);
	uintptr_t address = driver->GetModuleBaseAddr("BlackOpsColdWar.exe");
	uintptr_t processid = driver->GetProcessID("BlackOpsColdWar.exe");
	HWND yesDaddy = FindWindowA(NULL, "Call of Duty®: Black Ops Cold War");
	GetWindowThreadProcessId(yesDaddy, &oofBoiii);
	HANDLE discordOverlay = OpenProcess(PROCESS_ALL_ACCESS, FALSE, oofBoiii);
	uintptr_t PC_ArraySize_Offset = 0xB930;
	uintptr_t playerBase = address + 0x119503A0; //updated
	uintptr_t zombieBase = 0x68;
	uintptr_t botListBase = playerBase + 0x68;
	uintptr_t playerPedBase = playerBase + 0x8;
	uintptr_t jumpHeightBase = address + 0x10A456C0 + 0x8; //0x130 //broken
	uintptr_t zombieBotListBase = botListBase + 0x8;
	uintptr_t ZM_Bot_ArraySize_Offset = 0x5F8;
	uintptr_t ZM_Bot_Health = 0x398;
	uintptr_t XPScaleBase = 0x11980398; //updated
	uintptr_t InfraredVision = 0xE66; // (byte) On=0x10|Off=0x0
	uintptr_t cmdBufferBase = 0xDC753F0; //update
	uintptr_t CMDBB_Exec = -0x1B;
	uintptr_t nextZombieBot = 0x8;
	uintptr_t rankOffset = 0x28; //issue
	uintptr_t rankOffset2 = 0x20; //issue
	uintptr_t weaponOffset = 0x30; //blah
	uintptr_t rankValue = 1000.f;
	uintptr_t playerKills = 0x5D28;
	uintptr_t playerNameOffset = 0x5C1A;
	uintptr_t playerName = 0x5C1A;
	uintptr_t godMode = 0xE67; 
	uintptr_t points = 0x5D24; //fixed this
	uintptr_t runSpeed = 0x5C60; //broken
	uintptr_t playerArray = 0xB930; //0xB940 who knows
	uintptr_t zombieCritAddr = 0x10D8; //fixed
	uintptr_t CritKill1 = 0x10CC;
    uintptr_t CritKill2 = 0x10D0;
	uintptr_t CritKill3 = 0x10E4;
	uintptr_t CritKill4 = 0x10E8;
	uintptr_t CritKill5 = 0x10C4;
	uintptr_t CritKill6 = 0x10C8;

	//runspeed: 0x5C70


	uintptr_t zombieHealth = 0x398;
	uintptr_t zombieMaxHealth = 0x39C;
	uintptr_t setWeapon = 0xB0;

	uintptr_t ammo = 0x13D4;
	uintptr_t ammo1 = 0x13D4 + 1 * 0x4;
	uintptr_t ammo2 = 0x13D4 + 2 * 0x4;
	uintptr_t ammo3 = 0x13D4 + 3 * 0x4;
	uintptr_t ammo4 = 0x13D4 + 4 * 0x4;
	uintptr_t ammo5 = 0x13D4 + 5 * 0x4;
	uintptr_t ammo6 = 0x13D4 + 6 * 0x4;
	uintptr_t blank = 0;
	uintptr_t jumpHeightOffset = 0x130; //???????
	float currentZombieCordsValue[] = { 0, 0, 0 };
	uintptr_t goddamn1 = 0;
	uintptr_t p1WC = 0;
	uintptr_t p2WC = 0;
	uintptr_t p3WC = 0;
	uintptr_t p4WC = 0;
	uintptr_t p1LC = 0;
	uintptr_t p2LC = 0;
	uintptr_t p3LC = 0;
	uintptr_t p4LC = 0;
	uintptr_t p1TC = 0;
	uintptr_t p2TC = 0;
	uintptr_t p3TC = 0;
	uintptr_t p4TC = 0;
	uintptr_t p1FUC = 0;
	uintptr_t p2FUC = 0;
	uintptr_t p3FUC = 0;
	uintptr_t p4FUC = 0;
	uintptr_t p1WWC = 0;
	uintptr_t p2WWC = 0;
	uintptr_t p3WWC = 0;
	uintptr_t p4WWC = 0;
	uintptr_t p1KSC = 0;
	uintptr_t Camo = (address + 0x10E83880) + 0x1205A4;
	//uintptr_t Index = 0x1E5B6;//0x37860
	// Main Weapons
	vector<uintptr_t> p1W = { 49, 5, 11, 47, 26, 46, 29, 38, 54, 41, 17, 14, 43, 40, 32, 35, 34, 31, 2, 44, 57, 28, 45, 4, 15, 19, 25, 33, 48, 56, 21, 10, 12, 24, 27, 9, 8 };
	vector<uintptr_t> p2W = { 49, 5, 11, 47, 26, 46, 29, 38, 54, 41, 17, 14, 43, 40, 32, 35, 34, 31, 2, 44, 57, 28, 45, 4, 15, 19, 25, 33, 48, 56, 21, 10, 12, 24, 27, 9, 8 };
	vector<uintptr_t> p3W = { 49, 5, 11, 47, 26, 46, 29, 38, 54, 41, 17, 14, 43, 40, 32, 35, 34, 31, 2, 44, 57, 28, 45, 4, 15, 19, 25, 33, 48, 56, 21, 10, 12, 24, 27, 9, 8 };
	vector<uintptr_t> p4W = { 49, 5, 11, 47, 26, 46, 29, 38, 54, 41, 17, 14, 43, 40, 32, 35, 34, 31, 2, 44, 57, 28, 45, 4, 15, 19, 25, 33, 48, 56, 21, 10, 12, 24, 27, 9, 8 };
	// Tacticals
	vector<uintptr_t> p1T = { 39, 163, 120, 7, 20 };
	vector<uintptr_t> p2T = { 39, 163, 120, 7, 20 };
	vector<uintptr_t> p3T = { 39, 163, 120, 7, 20 };
	vector<uintptr_t> p4T = { 39, 163, 120, 7, 20 };
	// Lethals
	vector<uintptr_t> p1L = { 22, 50, 123, 13, 42 };
	vector<uintptr_t> p2L = { 22, 50, 123, 13, 42 };
	vector<uintptr_t> p3L = { 22, 50, 123, 13, 42 };
	vector<uintptr_t> p4L = { 22, 50, 123, 13, 42 };
	// Field Updgrades
	vector<uintptr_t> p1FU = { 296, 245, 295, 225, 285, 239 };
	vector<uintptr_t> p2FU = { 296, 245, 295, 225, 285, 239 };
	vector<uintptr_t> p3FU = { 296, 245, 295, 225, 285, 239 };
	vector<uintptr_t> p4FU = { 296, 245, 295, 225, 285, 239 };
	// Wonder Weapons
	vector<uintptr_t> p1WW = { 6, 350, 23, 36 };
	vector<uintptr_t> p2WW = { 6, 350, 23, 36 };
	vector<uintptr_t> p3WW = { 6, 350, 23, 36 };
	vector<uintptr_t> p4WW = { 6, 350, 23, 36 };
	// Kill Streaks
	vector<uintptr_t> p1KS = { 206, 68, 108, 149, 165, 293, 102, 64, 77, 72, 150 };
	vector<uintptr_t> p2KS = { 206, 68, 108, 149, 165, 293, 102, 64, 77, 72, 150 };
	vector<uintptr_t> p3KS = { 206, 68, 108, 149, 165, 293, 102, 64, 77, 72, 150 };
	vector<uintptr_t> p4KS = { 206, 68, 108, 149, 165, 293, 102, 64, 77, 72, 150 };

	vector<uintptr_t> goddamn = { 66, 8, 16, 62, 37, 61, 40, 45,  50, 71, 54, 25, 20, 56, 53, 59, 17, 43, 47, 46, 42, 4,  5, 57, 75, 65,  39, 58, 7, 63, 36, 44, 64, 73, 22, 27, 35, 12, 29, 15, 13, 10, 52, 18, 38, 34, 6, 14, 31, 21, 23 };
	vector<uintptr_t> ARs = { 66, 8, 16, 62, 37, 61, 40, 45 };
	vector<uintptr_t> SUBs = { 50, 71, 54, 25, 20, 56, 53, 59, 17 };
	vector<uintptr_t> TAC = { 43, 47, 46, 42, 4 };
	vector<uintptr_t> LMG = { 5, 57, 75, 65 };
	vector<uintptr_t> SNIP = { 39, 58, 7, 63, 36 };
	vector<uintptr_t> OTHER = { 44, 64, 73 };
	vector<uintptr_t> PIST = { 22, 27, 35, 12 };
	vector<uintptr_t> LAUNCH = { 29, 15, 13, 10, 52 };
	vector<uintptr_t> MELLEE = { 18, 38, 34, 6, 14, 31, 21, 23 };

	// Other Weapons
	vector<uintptr_t> XM4 = { 66 };
	vector<uintptr_t> AK47 = { 8 };
	vector<uintptr_t> KRIG6 = { 16 };
	vector<uintptr_t> QBZ83 = { 62 };
	vector<uintptr_t> FFAR1 = { 37 };
	vector<uintptr_t> GROZA = { 61 };
	vector<uintptr_t> FARA83 = { 40 };
	vector<uintptr_t> C58 = { 45 };

	vector<uintptr_t> MP5 = { 50 };
	vector<uintptr_t> MILANO821 = { 71 };
	vector<uintptr_t> AK74U = { 54 };
	vector<uintptr_t> KSP45 = { 25 };
	vector<uintptr_t> BULLFROG = { 20 };
	vector<uintptr_t> MAC10 = { 56 };
	vector<uintptr_t> LC10 = { 53 };
	vector<uintptr_t> PPSH41 = { 59 };
	vector<uintptr_t> OTS = { 17 };

	vector<uintptr_t> TYPE63 = { 43 };
	vector<uintptr_t> M16 = { 47 };
	vector<uintptr_t> AUG = { 46 };
	vector<uintptr_t> DMR14 = { 42 };
	vector<uintptr_t> CARV2 = { 4 };

	vector<uintptr_t> STONER63 = { 5 };
	vector<uintptr_t> RPD = { 57 };
	vector<uintptr_t> M60 = { 75 };
	vector<uintptr_t> MG82 = { 65 };

	vector<uintptr_t> PELINGTON703 = { 39 };
	vector<uintptr_t> LW3TUNDRA = { 58 };
	vector<uintptr_t> M82 = { 7 };
	vector<uintptr_t> ZRG20MN = { 63 };
	vector<uintptr_t> K31SUISSE = { 36 };

	vector<uintptr_t> HAUER77 = { 44 };
	vector<uintptr_t> GALLOSA12 = { 64 };
	vector<uintptr_t> BALAYEUSE = { 73 };

	vector<uintptr_t> P1911 = { 22 };
	vector<uintptr_t> MAGNUM = { 27 };
	vector<uintptr_t> DIAMATTI = { 35 };
	vector<uintptr_t> AMP63 = { 12 };

	vector<uintptr_t> CIGMA2 = { 29 };
	vector<uintptr_t> RPG7 = { 15 };
	vector<uintptr_t> M79 = { 13 };
	vector<uintptr_t> ARBALETTE = { 10 };
	vector<uintptr_t> PISTOLETCLOUE = { 52 };

	vector<uintptr_t> COUTEAU = { 18 };
	vector<uintptr_t> WAKIZASHI = { 38 };
	vector<uintptr_t> MASSE = { 34 };
	vector<uintptr_t> PELLE = { 6 };
	vector<uintptr_t> MACHETTE = { 14 };
	vector<uintptr_t> COUTEAUBALISTIQUE = { 31 };
	vector<uintptr_t> BATTEDEBASBALL = { 21 };
	vector<uintptr_t> MASSUE = { 23 };



	// Camo Shit
	vector<unsigned int> camo1 = { 0xC3, 0x09 };
	vector<unsigned int> camo2 = { 0x22 };
	vector<unsigned int> camo3 = { 0x18 };
	vector<unsigned int> camo4 = { 0x0E };
	vector<unsigned int> camo5 = { 0x09 };
	uintptr_t camoPtr = address + 0x10E83880;
	uintptr_t cammoFuck = FindDMAAddy(discordOverlay, camoPtr, camoOffset);
	uintptr_t cammoFuck2 = FindDMAAddy(discordOverlay, camoPtr, camoOffset2);
	uintptr_t cammoFuck3 = FindDMAAddy(discordOverlay, camoPtr, camoOffset3);
	uintptr_t cammoFuck4 = FindDMAAddy(discordOverlay, camoPtr, camoOffset4);
	uintptr_t currentPlayerCords = FindDMAAddy(discordOverlay, playerBase, playerCordsOffset);
	ReadProcessMemory(discordOverlay, (uintptr_t*)currentPlayerCords, &currentZombieCordsValue, sizeof(currentZombieCordsValue), nullptr);
	

	uintptr_t currentPlayerCords = FindDMAAddy(discordOverlay, playerBase, playerCordsOffset);
	//ReadProcessMemory(discordOverlay, (uintptr_t*)currentPlayerCords, &currentZombieCordsValue, sizeof(currentZombieCordsValue), nullptr);








	while (true)
	{
		
		if (driver->GetProcessID("BlackOpsColdWar.exe") == false)
		{
			exit(0);
		}
		/*
		*	Player 1 Features
		*/
		if (InstaKill)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(botListBase) + ZM_Bot_ArraySize_Offset + (ZM_Bot_Health), 1);
		}
		if (InstaKill == false)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(botListBase) + ZM_Bot_ArraySize_Offset + (ZM_Bot_Health), 0);
		}
		if (Infrared)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + InfraredVision, 0x10);
		}
		if (Infrared == false)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + InfraredVision, 0x00);
		}
		if (infiniteHealth)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + godMode, 0xA0);
		}
		if (infiniteHealth == false)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + godMode, 0x20);
		}
		if (infiniteAmmo)
		{
			for (uintptr_t a = 1; a < 6; a++)
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + ammo + (a * 0x4), 20); //20 used to be 5
			}
		}
		if (infinitePoints)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + points, 31222);
		}
		if (alwaysInstaKill)
		{
			for (uintptr_t i = 5; i < 200; i++)
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerPedBase) + 0x398 + (0x5F8 * i), 1);
			}
		}
		if (alwaysCrit)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + zombieCritAddr, -1);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + CritKill1, -1);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + CritKill2, -1);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + CritKill3, -1);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + CritKill4, -1);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + CritKill5, -1);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + CritKill6, -1);
		}
		if (playerRankXP)
		{
			driver->WriteMemory(address + XPScaleBase + rankOffset, xpval);
			driver->WriteMemory(address + XPScaleBase + rankOffset2,xpval);
		}
		if (playerWeaponXP)
		{
			driver->WriteMemory(address + XPScaleBase + weaponOffset, xpval);
		}
		if (jumpHeight)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(jumpHeightBase) + jumpHeightOffset, 200.f);
		}
		if (jumpHeight == false)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(jumpHeightBase) + jumpHeightOffset, 39.f);
		}


		//testing new gun cycle for regular weapons
		if (gunCycle2) {
			if (GetAsyncKeyState(VK_NUMPAD2))
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + setWeapon, goddamn[goddamn1]);
				goddamn1++;
				Sleep(500);
			}
			if (goddamn1 == 23) {
				goddamn1 = 0;
			}
		}

		if (p1WCycle)
		{
			if (GetAsyncKeyState(VK_NUMPAD1))
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + setWeapon, p1W[p1WC]);
				p1WC++;
				Sleep(500);
			}
			if (p1WC == 37)
			{
				p1WC = 0;
			}
		}
		if (p1LCycle)
		{
			if (GetAsyncKeyState(0x4C)) //L
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + setWeapon + 1 * 0x40, p1L[p1LC]);
				p1LC++;
				Sleep(500);
			}
			if (p1LC == 5)
			{
				p1LC = 0;
			}
		}
		if (p1TCycle)
		{
			if (GetAsyncKeyState(0x54)) //T
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + setWeapon + 2 * 0x40, p1T[p1TC]);
				p1TC++;
				Sleep(500);
			}
			if (p1TC == 5)
			{
				p1TC = 0;
			}
		}
		if (p1FUCycle)
		{
			if (GetAsyncKeyState(0x37)) //7
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + setWeapon + 3 * 0x40, p1FU[p1FUC]);
				p1FUC++;
				Sleep(500);
			}
			if (p1FUC == 6)
			{
				p1FUC = 0;
			}
		}
		if (p1WWCycle)
		{
			if (GetAsyncKeyState(0x38)) //8
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + setWeapon, p1WW[p1WWC]);
				p1WWC++;
				Sleep(500);
			}
			if (p1WWC == 4)
			{
				p1WWC = 0;
			}
		}



		if (p1Speed)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + runSpeed, 2.f);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 1 * playerArray + runSpeed, 2.f);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 2 * playerArray + runSpeed, 2.f);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 3 * playerArray + runSpeed, 2.f);
		}
		if (p1Speed == false)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + runSpeed, 1.f);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 1 * playerArray + runSpeed, 1.f);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 2 * playerArray + runSpeed, 1.f);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 3 * playerArray + runSpeed, 1.f);
		}
		if (zombieTP)
		{
			for (uintptr_t i = 5; i < 200; i++)
			{
				//this is where it's writing........
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerPedBase) + 0x2D4 + (0x5F8 * i), currentZombieCordsValue);
			}
		}


		if (newZombieLocation)
		{
			//figure out where it's writing cords and where you are, then paying add a few cords above or infront of you
			ReadProcessMemory(discordOverlay, (uintptr_t*)currentPlayerCords, &currentZombieCordsValue, sizeof(currentZombieCordsValue), nullptr);
			newZombieLocation = false;
		}
		if (GetAsyncKeyState(0x5A))
		{
			ReadProcessMemory(discordOverlay, (uintptr_t*)currentPlayerCords, &currentZombieCordsValue, sizeof(currentZombieCordsValue), nullptr);
		}

		if (restartGame)
		{
			string CMDCOMMAND = "full_restart;";
			//string CMDCOMMAND = "map_restart;"; //does not work
			//string CMDCOMMAND = "fast_restart;";
			driver->WriteMemory((address + cmdBufferBase), CMDCOMMAND);
			driver->WriteMemory((address + cmdBufferBase) + CMDBB_Exec, true);
			restartGame = false;
			exit(0);
		}
		if (disconnectGame)
		{
			string CMDCOMMAND = "disconnect;";
			driver->WriteMemory((address + cmdBufferBase), CMDCOMMAND);
			driver->WriteMemory((address + cmdBufferBase) + CMDBB_Exec, true);
			disconnectGame = false;
			exit(0);
		}
		if (publicGame)
		{
			string CMDCOMMAND = "public_match;";
			driver->WriteMemory((address + cmdBufferBase), CMDCOMMAND);
			driver->WriteMemory((address + cmdBufferBase) + CMDBB_Exec, true);
			publicGame = false;
			exit(0);
		}
		if (privateGame)
		{
			string CMDCOMMAND = "mp_customgame_private;";
			driver->WriteMemory((address + cmdBufferBase), CMDCOMMAND);
			driver->WriteMemory((address + cmdBufferBase) + CMDBB_Exec, true);
			privateGame = false;
			exit(0);
		}


		if (quickStart)
		{ 
			string CMDCOMMAND = "lobbyLaunchGame;";
			driver->WriteMemory((address + cmdBufferBase), CMDCOMMAND);
			driver->WriteMemory((address + cmdBufferBase) + CMDBB_Exec, true);
			quickStart = false;
			exit(0);
		}


		/*
		if (blaznOneShot)
		{
			for (ULONG i = 0; i < 142; i++)
			{
				driver->WriteMemory(cammoFuck + (0x80 * i), camo1);
				driver->WriteMemory(cammoFuck + 0x09 + (0x80 * i), camo1);
				driver->WriteMemory(cammoFuck + 0x12 + (0x80 * i), camo1);
				driver->WriteMemory(cammoFuck + 0x1C + (0x80 * i), camo2);
				driver->WriteMemory(cammoFuck + 0x1D + (0x80 * i), camo2);
				driver->WriteMemory(cammoFuck + 0x28 + (0x80 * i), camo3);
				driver->WriteMemory(cammoFuck + 0x36 + (0x80 * i), camo4);
				driver->WriteMemory(cammoFuck + 0x41 + (0x80 * i), camo5);
				driver->WriteMemory(cammoFuck + 0x52 + (0x80 * i), camo5);
			}
			blaznOneShot = false;
		}*/

		/*
		*	Player 2 Features
		*/
		if (p2infiniteHealth)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 1 * playerArray + godMode, 0xA0);
		}
		if (p2infiniteHealth == false)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 1 * playerArray + godMode, 0x20);
		}
		if (p2infiniteAmmo)
		{
			for (uintptr_t a = 1; a < 6; a++)
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 1 * playerArray + ammo + (a * 0x4), 20); //20 used to be 5
			}
		}
		if (p2infinitePoints)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 1 * playerArray + points, 33450);
		}
		if (p2alwaysCrit)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 1 * playerArray + zombieCritAddr, -1);
		}
		if (p2WCycle)
		{
			// Kb 4
			if (GetAsyncKeyState(VK_NUMPAD2))
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 1 * playerArray + setWeapon, p2W[p2WC]);
				p2WC++;
				Sleep(500);
			}
			if (p2WC == 37)
			{
				p2WC = 0;
			}
		}
		if (p2LCycle)
		{
			// Kb 5
			if (GetAsyncKeyState(0x35))
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 1 * playerArray + setWeapon + 1 * 0x40, p2L[p2LC]);
				p2LC++;
				Sleep(500);
			}
			if (p2LC == 5)
			{
				p2LC = 0;
			}
		}
		if (p2TCycle)
		{
			// Kb 6
			if (GetAsyncKeyState(0x36))
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 1 * playerArray + setWeapon + 2 * 0x40, p2T[p2TC]);
				p2TC++;
				Sleep(500);
			}
			if (p2TC == 5)
			{
				p1TC = 0;
			}
		}
		if (p2FUCycle)
		{

			if (GetAsyncKeyState(0x32))
			{
				// Kb Num1
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 1 * playerArray + setWeapon + 3 * 0x40, p2FU[p2FUC]);
				p2FUC++;
				Sleep(500);
			}
			if (p2FUC == 6)
			{
				p2FUC = 0;
			}
		}
		if (p2WWCycle)
		{
			// Kb Num2
			if (GetAsyncKeyState(0x31))
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 1 * playerArray + setWeapon, p2WW[p2WWC]);
				p2WWC++;
				Sleep(500);
			}
			if (p2WWC == 4)
			{
				p2WWC = 0;
			}
		}
		/*
		*	Player 3 Features
		*/
		if (p3infiniteHealth)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 2 * playerArray + godMode, 0xA0);
		}
		if (p3infiniteHealth == false)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 2 * playerArray + godMode, 0x20);
		}
		if (p3infiniteAmmo)
		{
			for (uintptr_t a = 1; a < 6; a++)
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 2 * playerArray + ammo + (a * 0x4), 20);
			}
		}
		if (p3infinitePoints)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 2 * playerArray + points, 32265);
		}
		if (p3alwaysCrit)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 2 * playerArray + zombieCritAddr, -1);
		}
		if (p3WCycle)
		{
			// Kb 9
			if (GetAsyncKeyState(VK_NUMPAD3))
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 2 * playerArray + setWeapon, p3W[p3WC]);
				p3WC++;
				Sleep(500);
			}
			if (p3WC == 37)
			{
				p3WC = 0;
			}
		}
		if (p3LCycle)
		{
			// Kb 0
			if (GetAsyncKeyState(0x30))
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 2 * playerArray + setWeapon + 1 * 0x40, p3L[p3LC]);
				p3LC++;
				Sleep(500);
			}
			if (p3LC == 5)
			{
				p3LC = 0;
			}
		}
		if (p3TCycle)
		{
			// Kb -
			if (GetAsyncKeyState(0xBD))
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 2 * playerArray + setWeapon + 2 * 0x40, p3T[p3TC]);
				p3TC++;
				Sleep(500);
			}
			if (p3TC == 5)
			{
				p3TC = 0;
			}
		}
		if (p3FUCycle)
		{

			if (GetAsyncKeyState(VK_BROWSER_FAVORITES))
			{
				// Kb Num1
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 2 * playerArray + setWeapon + 3 * 0x40, p3FU[p3FUC]);
				p3FUC++;
				Sleep(500);
			}
			if (p3FUC == 6)
			{
				p3FUC = 0;
			}
		}
		if (p3WWCycle)
		{
			// Kb Num2
			if (GetAsyncKeyState(VK_BROWSER_STOP))
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 2 * playerArray + setWeapon, p3WW[p3WWC]);
				p3WWC++;
				Sleep(500);
			}
			if (p3WWC == 4)
			{
				p3WWC = 0;
			}
		}
		/*
		*	Player 4 Features
		*/
		if (p4infiniteHealth)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 3 * playerArray + godMode, 0xA0);
		}
		if (p4infiniteHealth == false)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 3 * playerArray + godMode, 0xA0);
		}
		if (p4infiniteAmmo)
		{
			for (uintptr_t a = 1; a < 6; a++)
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 3 * playerArray + ammo + (a * 0x4), 20);
			}
		}
		if (p4infinitePoints)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 3 * playerArray + points, 36950);
		}
		if (p4alwaysCrit)
		{
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 3 * playerArray + zombieCritAddr, -1);
		}
		if (p3WCycle)
		{
			// Kb <
			if (GetAsyncKeyState(VK_NUMPAD4))
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 3 * playerArray + setWeapon, p4W[p4WC]);
				p4WC++;
				Sleep(500);
			}
			if (p4WC == 37)
			{
				p4WC = 0;
			}
		}
		if (p3LCycle)
		{
			// Kb .
			if (GetAsyncKeyState(0xBE))
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 3 * playerArray + setWeapon + 1 * 0x40, p4L[p4LC]);
				p4LC++;
				Sleep(500);
			}
			if (p4LC == 5)
			{
				p4LC = 0;
			}
		}
		if (p3TCycle)
		{
			// Kb /
			if (GetAsyncKeyState(0xBF))
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 3 * playerArray + setWeapon + 2 * 0x40, p4T[p4TC]);
				p4TC++;
				Sleep(500);
			}
			if (p4TC == 5)
			{
				p4TC = 0;
			}
		}
		if (p3FUCycle)
		{

			if (GetAsyncKeyState(VK_GAMEPAD_DPAD_DOWN))
			{
				// Kb Num1
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 3 * playerArray + setWeapon + 3 * 0x40, p4FU[p4FUC]);
				p4FUC++;
				Sleep(500);
			}
			if (p4FUC == 6)
			{
				p4FUC = 0;
			}
		}
		if (p3WWCycle)
		{
			// Kb Num2
			if (GetAsyncKeyState(VK_NUMPAD8))
			{
				driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 3 * playerArray + setWeapon, p4WW[p4WWC]);
				p4WWC++;
				Sleep(500);
			}
			if (p4WWC == 4)
			{
				p4WWC = 0;
			}
		}
		if (GetAsyncKeyState(0x39))
		{
			/*
			*	Player 1 booleans
			*/
			
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + godMode, 0x20);
			
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(jumpHeightBase) + jumpHeightOffset, 39.f);
		
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + runSpeed, 1.f);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 1 * playerArray + runSpeed, 1.f);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 2 * playerArray + runSpeed, 1.f);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 3 * playerArray + runSpeed, 1.f);
		
			driver->WriteMemory(address + XPScaleBase + rankOffset, 1.f);
			driver->WriteMemory(address + XPScaleBase + rankOffset2, 1.f);
			
			driver->WriteMemory(address + XPScaleBase + weaponOffset, 1.f);
	
			/*
			*	Player 2 booleans
			*/
			
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 1 * 0xB900 + godMode, 0x20);
	
			/*
			*	Player 3 booleans
			*/
			
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 2 * 0xB900 + godMode, 0x20);
		
			/*
			*	Player 4 booleans
			*/
			
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 3 * 0xB900 + godMode, 0x20);
		
		}
		if (GetAsyncKeyState(VK_HOME))
		{
			/*
			*	Player 1 booleans
			*/
			
			
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + godMode, 0x20);
			
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(jumpHeightBase) + jumpHeightOffset, 39.f);
		
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + runSpeed, 1.f);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 1 * playerArray + runSpeed, 1.f);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 2 * playerArray + runSpeed, 1.f);
			driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 3 * playerArray + runSpeed, 1.f);
			
			driver->WriteMemory(address + XPScaleBase + rankOffset, 1.f);
			driver->WriteMemory(address + XPScaleBase + rankOffset2, 1.f);
		
			driver->WriteMemory(address + XPScaleBase + weaponOffset, 1.f);
		
			
			p2infiniteHealth = false; driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 1 * 0xB900 + godMode, 0x20);
		
			p3infiniteHealth = false; driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 2 * 0xB900 + godMode, 0x20);
		
		
			p4infiniteHealth = false; driver->WriteMemory(driver->ReadMemory<uintptr_t>(playerBase) + 3 * 0xB900 + godMode, 0x20);
	

			exit(0);
		}
	}

}
class Vector3 {
public:
	float x, y, z;
	Vector3() : x(0.f), y(0.f), z(0.f) {}
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

	void zombieCordsV()
	{
		x = -x;
		y = -y;
		z = -z;
	}
};

int main()
{

	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 500, 300, TRUE);
	

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



	//DoBypassInstaller();
	axeraMenuBody();



	main();

}






















