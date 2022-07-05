#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

enum en_DIRS {NORTH, EAST, SOUTH, WEST};

//enum the rooms
enum en_ROOMS{ENTRANCE, MAZE, ANTECHAMBER, BALLROOM_CHAMBER, MUTE_CHAMBER, BANQUET_HALL, GUARD_Maze, DAMP_CHAMBER, UNDERGROUNDS, DANGEROUS_SNAKE, Maze_Quarters, VENOMOUS_UNDERGROUNDS, CRYPT, HAUNTED_UNDERGROUNDS, Crypt_Cave, Barracks_Cave, SNAKE, CRYPT_Maze, Cavernes_Maze, FAST_SNAKE, Crypt_SNAKE, DEN, STORE_ROOM, CAVE_DEN, MONARCH, Wild_DEN, Killing_ROOM, CAVE_ROOM, Haunt_Guardian, GUARDIAN, SCORCHED_Guardian, Death_MONARCH, FRENCH_MONARCH, CHATIMENT_Guardian, SECRET_ROOM, WILD_UNDERGROUNDS
};

//enum verbs
enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK, SLEEP, TALK};

//enum nouns
enum en_NOUNS {KEYS, BOX, TREASURE, Dragon_Croc, VENOM_GLAVE, SWORD, TAMA, SHIRT, VAMBRACE, VEST, BENCH, SECRET_GADGET, SKELETON, GOLD, COINS, SHIELD, STORAGE, LAMP, BED, TABLE, ARMCHAIR, BOOK, STONE, ROPE};


const int NONE = -1;
const int DIRS = 4;
const int ROOMS = 36;
const int VERBS = 10;
const int NOUNS = 24;

//.............................................................
class Words{
    private:			//Private variables for Words
	  string m_Word;
	  int m_Code;
	  public:				// Public Variables for Words
	  Words(string gWord, int gCode):
	  m_Word(gWord),m_Code(gCode){}

  	string GetWord(){return m_Word;}
  	int GetCode(){return m_Code;}
};
//................................................................
class Room{
	  private:
	  string mDescription;
	  int mExitsToRoom[DIRS];
	  int m_Code;
	  public:
	  Room(string gDesc, int gNorth, int gEast, int gSouth, int gWest, int code):
	  mDescription(gDesc), m_Code(code){
		    mExitsToRoom[NORTH] = gNorth;
		    mExitsToRoom[EAST] = gEast;
		    mExitsToRoom[SOUTH] = gSouth;
		    mExitsToRoom[WEST] = gWest;
	}

	  int GetCode(){return m_Code;}
	  int getExitsToRoom(int givenInt){return mExitsToRoom[givenInt];}
	  string GetDescription(){return mDescription;}

	//Public Variables initialisation
	  void setExitsToRoom(int givenRoom, int givenDir){mExitsToRoom[givenDir] = givenRoom;}
	  void setDescription(string givenStr){mDescription = givenStr;}
};
//...................................................................
class Noun{
	  private:
	  string m_Word;
	  string mDescription;
	  int m_Code;
	  int mLocation;
	  bool mCanCarry;
	  public:
	  Noun(string gWord, string gDesc, int gCode, int givenLoc, bool 
    givenCanCarry):m_Word(gWord), mDescription(gDesc), m_Code(gCode), mLocation(givenLoc), 
    mCanCarry(givenCanCarry){}


	//Public Variables initialisation
	  void clearDescription(){mDescription.clear();}
	  int GetLocation(){return mLocation;}
	  int GetCode(){return m_Code;}
	  bool
	  GetCanCarry(){return mCanCarry;}
	  string GetWord(){return m_Word;}
	  string GetDescription(){return mDescription;}
	  void SetDescorption(string givenStr){mDescription = givenStr; }
	  void SetLocation(int givenLoc){mLocation = givenLoc;}
};
//.......................................................................ROOMS
void set_rooms(vector<Room> &rms){
	//rms.push_back(Room(gDesc, gNorth, gEast, gSouth, gWest, code));
	  rms.push_back(Room("BIG ENTRANCE", NONE, NONE, ANTECHAMBER, NONE, ENTRANCE));

	  rms.push_back(Room("ANTECHAMBER", ENTRANCE, NONE, BALLROOM_CHAMBER,NONE, ANTECHAMBER));
	  rms.push_back(Room("BALLROOM CHAMBER", NONE, NONE, MUTE_CHAMBER, NONE, BALLROOM_CHAMBER));
	  rms.push_back(Room("MUTE CHAMBER", BALLROOM_CHAMBER, NONE, BANQUET_HALL, NONE, MUTE_CHAMBER));
	  rms.push_back(Room("BANQUET HALL", MUTE_CHAMBER, UNDERGROUNDS, Maze_Quarters, MAZE, BANQUET_HALL));
	  rms.push_back(Room("Maze Quarters", BANQUET_HALL, SNAKE, NONE, CRYPT, Maze_Quarters));
	  rms.push_back(Room("UNDERGROUNDS", NONE, VENOMOUS_UNDERGROUNDS, BANQUET_HALL, CRYPT, UNDERGROUNDS));
	  rms.push_back(Room("VENOMOUS UNDERGROUND", NONE, HAUNTED_UNDERGROUNDS, Crypt_Cave, UNDERGROUNDS, VENOMOUS_UNDERGROUNDS));
	  rms.push_back(Room("HAUNTED UNDERGROUND", WILD_UNDERGROUNDS, NONE, Barracks_Cave, VENOMOUS_UNDERGROUNDS, HAUNTED_UNDERGROUNDS));
	  rms.push_back(Room("Wild Underground", NONE, NONE, HAUNTED_UNDERGROUNDS, NONE, WILD_UNDERGROUNDS));
	

	  rms.push_back(Room("MAZE", NONE, BANQUET_HALL, SNAKE, CRYPT_Maze, MAZE));
	  rms.push_back(Room("CRYPT Maze", NONE, MAZE, FAST_SNAKE, Cavernes_Maze,CRYPT_Maze));
	  rms.push_back(Room("Cavernes_Maze", GUARD_Maze, CRYPT_Maze, Crypt_SNAKE, NONE, Cavernes_Maze));
	  rms.push_back(Room("GUARD MAZE", NONE, NONE, Cavernes_Maze, NONE, GUARD_Maze));
	  rms.push_back(Room("SNAKE", MAZE, Maze_Quarters, NONE, FAST_SNAKE, SNAKE));
  	rms.push_back(Room("FAST SNAKE", CRYPT_Maze, SNAKE, STORE_ROOM, Crypt_SNAKE, FAST_SNAKE));
	  rms.push_back(Room("Crypt SNAKE ", Cavernes_Maze, FAST_SNAKE, NONE, NONE, Crypt_SNAKE));

	  rms.push_back(Room("CRYPT", UNDERGROUNDS, Crypt_Cave, NONE, Maze_Quarters, CRYPT));
	  rms.push_back(Room("Crypt_SANKE", VENOMOUS_UNDERGROUNDS, Barracks_Cave, DEN, CRYPT, Crypt_Cave));
	  rms.push_back(Room("BARRACKS CAVE", HAUNTED_UNDERGROUNDS, NONE, NONE, Crypt_Cave, Barracks_Cave));
	  rms.push_back(Room("DEN", Crypt_Cave, NONE, NONE, CAVE_DEN, DEN));
	  rms.push_back(Room("Cave DEN", NONE, DEN, Wild_DEN, MONARCH, CAVE_DEN));
	  rms.push_back(Room("MONARCH", NONE, CAVE_DEN, Death_MONARCH, Killing_ROOM, MONARCH));
	  rms.push_back(Room("Killing Room", NONE, MONARCH, CAVE_ROOM, STORE_ROOM, Killing_ROOM));

	  rms.push_back(Room("STORE ROOM", FAST_SNAKE, Killing_ROOM, NONE, NONE, STORE_ROOM));
	  rms.push_back(Room("Death MONARCH", MONARCH, Wild_DEN, CAVE_ROOM, FRENCH_MONARCH, Death_MONARCH));
	  rms.push_back(Room("Wild DEN", CAVE_DEN, NONE, SCORCHED_Guardian, Death_MONARCH, Wild_DEN));
	  rms.push_back(Room("CAVE Room", Killing_ROOM, Death_MONARCH, Haunt_Guardian, SECRET_ROOM, CAVE_ROOM));
	  rms.push_back(Room("Secret Room", NONE, NONE, NONE ,CAVE_ROOM , SECRET_ROOM));
	  rms.push_back(Room("FRENCH MONARCH", Death_MONARCH, NONE, GUARDIAN, NONE, FRENCH_MONARCH));
	  rms.push_back(Room("GUARDIAN", FRENCH_MONARCH, SCORCHED_Guardian, DAMP_CHAMBER, Haunt_Guardian, GUARDIAN));
	  rms.push_back(Room("SCORCHED Guardian", Wild_DEN, GUARDIAN, NONE, CHATIMENT_Guardian , SCORCHED_Guardian));
	  rms.push_back(Room("CHATIMENT GUARDIAN", NONE, SCORCHED_Guardian, NONE, NONE , CHATIMENT_Guardian));


}
//.......................................................................SET DIRECTIONS
void set_directions(vector<Words> &dir){
	  dir.push_back(Words("NORTH", NORTH));
	  dir.push_back(Words("EAST", EAST));
	  dir.push_back(Words("SOUTH", SOUTH));
	  dir.push_back(Words("WEST", WEST));
}
//.......................................................................VERB SET
void set_verbs(vector<Words> &vbs){
    vbs.push_back(Words("GET", GET));
  	vbs.push_back(Words("DROP", DROP));
  	vbs.push_back(Words("USE", USE));
  	vbs.push_back(Words("OPEN", OPEN));
  	vbs.push_back(Words("CLOSE", CLOSE));
  	vbs.push_back(Words("EXAMINE", EXAMINE));
  	vbs.push_back(Words("INVENTORY", INVENTORY));
    vbs.push_back(Words("LOOK", LOOK));
  	vbs.push_back(Words("TALK", TALK));
    vbs.push_back(Words("SLEEP", SLEEP));
  }

void setnouns(vector<Noun> &nns){
  	//Noun(string gWord, string gDesc, int gCode, int givenLoc, bool givenCanCarry)
  	
    nns.push_back(Noun("KEYS", "the KEYS", KEYS, GUARD_Maze, true));
  	nns.push_back(Noun("KEYS", "the KEYS", KEYS, WILD_UNDERGROUNDS, true));
  	nns.push_back(Noun("SLEEP", "a Hylian SLEEP that resembles an Eagle", SLEEP, Crypt_Cave, true));
  	nns.push_back(Noun("BOX", "a closed BOX", BOX, DAMP_CHAMBER, false));
  	nns.push_back(Noun("BOX", "a closed BOX", BOX, DANGEROUS_SNAKE, false));
  	nns.push_back(Noun("Treasure", "some Treasure", TREASURE, MAZE, true));
  	nns.push_back(Noun("Treasure", "some Treasure", TREASURE, GUARD_Maze, true));
  	nns.push_back(Noun("Dragon_Croc", "a Iron Dragon_Croc", Dragon_Croc, MAZE, true));
  	nns.push_back(Noun("VENOM GLAVE", "a VENOM GLAVE", VENOM_GLAVE, GUARD_Maze, true));
  	nns.push_back(Noun("SWORD", "the Master Sword! (Type sword to get it)", SWORD, CHATIMENT_Guardian, true));
  	nns.push_back(Noun("TAMA", "African drum, made of animal skins.", TAMA, CHATIMENT_Guardian, true));
  	nns.push_back(Noun("SHIRT", "a long green pointed SHIRT", SHIRT, WILD_UNDERGROUNDS, true));
  	nns.push_back(Noun("VAMBRACE", "a Vambrace", VAMBRACE, SECRET_ROOM, true));
  	nns.push_back(Noun("VEST", "a Green VEST", VEST, WILD_UNDERGROUNDS, true));
  	nns.push_back(Noun("SHIELD", "an Alien Shield", SHIELD, STORE_ROOM, true));
  	nns.push_back(Noun("GOLD", "a pot of Gold", GOLD, DAMP_CHAMBER, true));
  	nns.push_back(Noun("ROPE", "A rope", ROPE, ENTRANCE, true));
  	nns.push_back(Noun("STONE", "A stone ", STONE, ENTRANCE, true));
  
  	// adding to environment
  	nns.push_back(Noun("BENCH", "a bench", BENCH, ENTRANCE, false));
  	nns.push_back(Noun("BENCH", "a bench", BENCH, GUARDIAN, false));
  	nns.push_back(Noun("Secret Gadget", "Secret Gadget", SECRET_GADGET, MUTE_CHAMBER, true));
  	nns.push_back(Noun("Secret Gadget", "an ancient Secret gadgets", SECRET_GADGET, GUARDIAN, true));
  	nns.push_back(Noun("RUPEES", "a bag of Rupees", COINS, Death_MONARCH, true));
  	nns.push_back(Noun("SKELETON", "a skeleton of SHIRT must have been an adventurer like yourself", SKELETON, Crypt_Cave, false));
  	nns.push_back(Noun("Storage", "some storage  holds venoumous animals corpes and Secret gadgets so old that they break when you touch the storage", STORAGE, Maze_Quarters, false));
  	nns.push_back(Noun("Storage", "some storage holds venomous animals corpes and Secret gadgets so old that they break when you touch the storage", STORAGE, GUARDIAN, false));
  	nns.push_back(Noun("LAMP", "a LAMP is lit on the wall. ", LAMP, ENTRANCE, true));
  	nns.push_back(Noun("BED", "a bed to SLEEP in", BED, DEN, false));
  	nns.push_back(Noun("TABLE", "a table", TABLE, ENTRANCE, false));
  	nns.push_back(Noun("ARMCHAIR", "An arm chair", ARMCHAIR, ENTRANCE, false));





}
//................................................................NEW FUNCTIONS
vector<Room>::iterator find(vector<Room> &rs, int r){
  	for(vector<Room>::iterator iter = rs.begin(); iter != rs.end(); iter++){
  		  if((*iter).GetCode() == r) return iter;
  	}
  	return rs.end();
  }

vector<Noun>::iterator find(vector<Noun> &nns, int r){
  	for(vector<Noun>::iterator iter = nns.begin(); iter != nns.end(); iter++){
  		  if((*iter).GetCode() == r) return iter;
  	}
  	return nns.end();
  }

vector<Words>::iterator find(vector<Words> &wrd, int r){
  	for(vector<Words>::iterator iter = wrd.begin(); iter != wrd.end(); iter++){
  		 if((*iter).GetCode() == r) return iter;
  	}
  	return wrd.end();
}

vector<Words>::iterator find(vector<Words> &wrd, string r){
  	for(vector<Words>::iterator iter = wrd.begin(); iter != wrd.end(); iter++){
  		 if((*iter).GetWord() == r) return iter;
  	}
  	return wrd.end();
}

vector<Noun>::iterator find(vector<Noun> &nns, string r){
  	for(vector<Noun>::iterator iter = nns.begin(); iter != nns.end(); iter++){
  		if((*iter).GetWord() == r) return iter;
  	}
  	return nns.end();
}
//................................................................COMMAND
void Command(string Cmd, string &wd1, string &wd2){
    string subStr;
  	vector<string> words;
	  char search = ' ';

  	for(int i = 0; i < Cmd.size(); i++ ){
    		if(Cmd[i] != search){subStr.insert(subStr.end(),Cmd[i]);}
    		if(i == Cmd.size() -1){
      			words.push_back(subStr);
      			subStr.clear();
    		}
    		if(Cmd[i] == search){
      			words.push_back(subStr);
      			subStr.clear();
    		}
  	}
  	for(int i=words.size()-1; i>0; i--){
    		if(words[i] == ""){
      			words.erase(words.begin() + i);
  		}
  	}
  	for(int i = 0; i < words.size(); i++){
    		for(int j = 0; j < words[i].size(); j++){
      			if(islower(words[i][j])){	words[i][j] = toupper(words[i][j]);}
  		}
  	}
  	if(words.size() == 0){cout <<"You did not enter a command\n" <<endl;	}
  	else if(words.size() == 1){wd1 = words[0];}
  	else if(words.size() == 2){wd1 = words[0]; wd2 = words[1];}
  	else if (words.size() >2){cout << "Please, your command must be more than two words (Verb then Noun)\n" << endl;}
}
//............................................................LOOK AROUND
void LookAround(int loc, vector<Room> &rms, vector<Words> &dir, vector<Noun> &nns){
  	cout << "You're in a " << (*find(rms,loc)).GetDescription() << "." << endl;
  
  	for(int i = 0; i < DIRS; i++){
    		if((*find(rms, loc)).getExitsToRoom(i) != NONE){
      			cout << "There is an exit " << (*find(dir,i)).GetWord() << " to a " <<(*find(rms, (*find(rms,loc)).getExitsToRoom((*find(dir,i)).GetCode()))).GetDescription()<< "." << endl;
    		}
  	}
  	for(int i = 0; i <NOUNS; i++){
    		if((*find(nns, i)).GetLocation() == loc){
      			cout << "You see " << (*find(nns, i)).GetDescription() << "." <<endl;
  		}
  	}
}
//.................................................................Parser
bool parser(int &loc, string wd1, string wd2, vector<Words> &dir, vector<Words> &vbs, vector<Room> &rms, vector<Noun> &inv, vector<Noun> &nns){
  	static bool BOX_state = false;
  	static bool lock = false;

  	for(int i = 0; i < DIRS; i++){
    		if(wd1 == (*find(dir,i)).GetWord()){
      			if((*find(rms,loc)).getExitsToRoom((*find(dir,i)).GetCode()) != NONE){
        				loc = (*find(rms,loc)).getExitsToRoom((*find(dir,i)).GetCode());
        				cout << "You are now in a " << (*find(rms,loc)).GetDescription() << "." <<endl;
        				if(loc == DAMP_CHAMBER || loc == DANGEROUS_SNAKE){
          					(*find(nns, BOX)).SetLocation(loc);
          				}
          				return true;
        			} else{
                  cout << "No exit that way." <<endl;
                  return true;
			}
		}
	}
  	vector<Noun>::iterator NOUN_MATCH = nns.end();
  	vector<Words>::iterator VERB_ACTION = vbs.end();

	//WORD 1 AND 2
  	if(find(vbs, wd1) != vbs.end()){
    		VERB_ACTION = find(vbs, wd1);
  	}
  	if(wd2 != "" && find(nns, wd2) != nns.end()){
    		NOUN_MATCH = find(nns, wd2);
  	}
  
  	//.....................................verbs actions
  	if(VERB_ACTION == vbs.end()){
    		cout << "No valid command entered." <<endl;
    		return true;
  	}
  
  	if((*VERB_ACTION).GetCode() == LOOK){
    		LookAround(loc,rms,dir,nns);
    		return true;
  	}
//.........................................................VERB COMMANDS
  	if((*VERB_ACTION).GetCode() == OPEN){ 			// Open
  		if((*NOUN_MATCH).GetCode() == BOX){
  			if(loc == DAMP_CHAMBER || loc == DANGEROUS_SNAKE){
  				if(BOX_state == false){
  					if(lock == true){
  						BOX_state = true;
  						(*find(nns,BOX)).SetDescorption("an open BOX");
  						cout << "The BOX has opened, inside you find a piece of a paper. One of two...." << endl;
  						nns.push_back(Noun("Book", "a book", BOOK, DAMP_CHAMBER, true));
  						nns.push_back(Noun("Book", "a book", BOOK, DANGEROUS_SNAKE, true));
  						return true;
  					} else {
  						cout << "The BOX is locked, unlock the BOX before opening it\n";
  						return true;
  					}
  				} else if(BOX_state == true){
  					cout << "The BOX is already open." <<endl;
  					return true;
  				}
  			}else {
  				cout << "There is no BOX to open here." <<endl;
  				return true;
  			}
  		} else {
  			cout << "Opening that is not possible." << endl;
  			return true;
		}
	}

	if((*VERB_ACTION).GetCode() == CLOSE){			//CLOSE VERB
	if((*NOUN_MATCH).GetCode() == BOX){
			if(loc == DAMP_CHAMBER || loc == DANGEROUS_SNAKE){
				if(BOX_state == true){
					if(lock == true){
						BOX_state = false;
						(*find(nns,BOX)).SetDescorption("a closed BOX");
						cout << "The BOX has closed" << endl;
						return true;
					} else if (lock == false){
						 cout << "The BOX is locked, unlock it with your KEYS first\n";
						 return true;
					}
				} else if(BOX_state == false){
					cout << "The BOX is already closed." <<endl;
					return true;
				}
			}else {
				cout << "There is no BOX to close here." <<endl;
				return true;
			}
		} else {
			cout << "Closing that is not possible." << endl;
			return true;
		}
	}

	if((*VERB_ACTION).GetCode() == USE){					//USE VERB
		if((*NOUN_MATCH).GetCode() == BOOK){
			if(find(inv, BOOK) != inv.end()){
				cout << "You need to get the other book!";
			}

			if(find(inv, BOOK * 2) != inv.end()){
				cout << "Once you have both books, you can trace the map of the DUNGEON. Congratulations, you have won!\n";
				return 0;
			}
		}
		if((*NOUN_MATCH).GetCode() == VENOM_GLAVE){
			if(find(inv, VENOM_GLAVE) != inv.end()){
				if(loc == CHATIMENT_Guardian){
					cout << "You thrust a stone with your slangshot, it hits a jar !! the sun goes through a hole that the jar hid!\n";
				}
				else if(loc == GUARD_Maze){
					cout << "You thrust a stone at the target and hit it in the center!\n";
				}
				else{
					cout << "This item cannot be used here\n";
				}
			}
		}
		else if((*NOUN_MATCH).GetCode() == KEYS){		// KEYS needed
			if(find(inv, KEYS) != inv.end()){
				if(loc == DAMP_CHAMBER || loc == DANGEROUS_SNAKE){
					if(lock == false){
						lock = true;
						cout << "The BOX has been unlocked\n";
						return true;
					} else if (lock == true){
						cout << "The BOX was unlocked\n";
						lock = false;
						cout << "The BOX is locked now\n";
						return true;
					}
				} else {
					cout << "Incorrect BOX\n";
					return true;
				}
			} else{
				cout << "You do not have this item in your inventory\n" << endl;
				return true;
			}
		} else {
			cout << "This item cannot be used (yet)\n";
			return true;
		}
	}

	if((*VERB_ACTION).GetCode() == EXAMINE ){			//EXAMINE VERB
		if(NOUN_MATCH != nns.end()){
			if((*NOUN_MATCH).GetLocation() == loc){
				cout << (*NOUN_MATCH).GetDescription() << endl;
			} else cout << "That is not in this room\n";
		} else cout << "Just Type look to see it.\n";
	}

	if((*VERB_ACTION).GetCode() == GET){ 				//GET VERB
		if(NOUN_MATCH != nns.end()){
			if((*NOUN_MATCH).GetLocation() == loc){
				if((*NOUN_MATCH).GetCanCarry()){
					cout << "You have picked up " << (*NOUN_MATCH).GetWord() << endl;
					(*NOUN_MATCH).SetLocation(NONE);
					inv.push_back((*NOUN_MATCH));
				return true;
				} cout << "This item can't be carried\n";
			} else cout << "That is not in this room\n";
		} else cout << "No noun\n";
	}

	if((*VERB_ACTION).GetCode() == DROP){				//DROP VERB
		if(NOUN_MATCH != nns.end()){
			if((*NOUN_MATCH).GetLocation() == NONE){
				cout << "You have dropped " << (*NOUN_MATCH).GetWord() << endl;
				(*NOUN_MATCH).SetLocation(loc);
				inv.erase(find(inv, (*NOUN_MATCH).GetCode()));
				return true;
			} else cout << "Not in room\n";
		} else cout << "Sorry, I don't know that command\n";
	}

	if((*VERB_ACTION).GetCode() == INVENTORY){			//INVENTORY VERB
		if(inv.size() > 0){
			cout <<"In your Backpack you have: \n";
			for(vector<Noun>::iterator i = inv.begin(); i != inv.end(); i++){
				cout <<"\t-" << (*i).GetWord() << endl;
			}
		} else cout << "You have nothing in your Backpack, you can pick up items that you find in the dungeon.";
	}
	//GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK
	if((*VERB_ACTION).GetCode() == TALK){ //TALK
		if((*NOUN_MATCH).GetCode() == SECRET_GADGET){
			if(find(inv, SECRET_GADGET) != inv.end()){
				cout << "The Secret Gadget will tell you a story about the first Hero, how he managed to beat the Boss evil thousands years !\n";
			}
			else{
				cout << "You do not have a Secret Gadget in your inventory\n";
			}
		}
		else{
			cout << "This cannot TALK\n";
		}
	}
	if((*VERB_ACTION).GetCode() == SLEEP){ //SLEEP
		if(loc == ENTRANCE || loc == GUARDIAN || loc == DEN){
			cout << "You can sleep and recharge to continue the adventure!\n";
		}
		else{
			cout << "You cannot SLEEP here, it is unsafe.....\n";
		}
	}
	return false;
}


int main() {
  	string command;
  	string word1;
  	string word2;
  
  	vector<Room> rooms;
  	set_rooms(rooms);
  
  	vector<Words> directions;
  	set_directions(directions);
  
  	vector<Words> verbs;
  	set_verbs(verbs);
  
  	vector<Noun> nouns;
  	setnouns(nouns);
  
  	vector<Noun> inventory;
  
  	int location = ENTRANCE;
  
    
  
w
  
  
  
  
  	do{
    		command.clear();
    		cout << "\nWhat will you do?\n(^_^) : ";
    		getline(cin, command);
    
    		word1.clear();
    		word2.clear();
    west
    		Command(command, word1, word2);
    
    		if(word1 != "QUIT"){
    			parser(location, word1, word2, directions, verbs, rooms, inventory, nouns);
    		}
    	}while(word1 != "QUIT");
    }
