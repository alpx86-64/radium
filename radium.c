/*  Radium - Remote Android Device Internals Utilities and Management
    Copyright (C) 2024  Alp A

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char add_cmd[50] = "adb install ";
char remove_cmd[50] = "adb shell pm uninstall --user 0 ";
char disable_cmd[50] = "adb shell pm disable-user --user 0 ";
char enable_cmd[50] = "adb shell pm enable ";

void package_action(char package[], char command[]);
void fetch_package(char weblink[]);
void execute(char command[]);

int main(int argc, char* args[]){
    if (argc < 3){
        printf("Usage: radium [options] [package]\n\n");
	printf("add [apk]            Install the specified APK file\n");
	printf("rm [package]         Uninstall the specified application (requires android package name like 'com.x.x')\n");
	printf("disable [package]    Disable the specified android package\n");
	printf("enable [package]     Enable the specified android package\n");
    }

    if (argc >= 3){
        if (strcmp(args[1], "add") == 0){
	    package_action(args[2], add_cmd);
	}
	if (strcmp(args[1], "rm") == 0){
	    package_action(args[2], remove_cmd);
	}
	if (strcmp(args[1], "disable") == 0){
	    package_action(args[2], disable_cmd);
	}
	if (strcmp(args[1], "enable") == 0){
	    package_action(args[2], enable_cmd);
	}
	
    }
}

void execute(char command[]){
    system(command);
}

void package_action(char package[], char command[]){
    strcat(command, package);
    execute(command);
}
