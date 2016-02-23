/*
    Shunt wound motor control firmware 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * Source file for temperature sensing functions
 */

double analog2temp(rawValue, sensorType) {
    double celsius = 0;

    switch(sensorType){
        case 1:
            const double tempTable[][2] = tempTable_1;
            break;
        default:
            //sensorType not recognised
            return celsius;
            break;
    }
    tempTableLen = sizeof(tempTable) / sizeof(tempTable[0]);

    int i;
    for(i=1; i<tempTableLen; i++){
        if (tempTable[i][0] > rawValue){
            celsius = tempTable[i-1] + 
                (raw - tempTable[i][0]) * 
                (double)(tempTable[i][1] - tempTable[i-1][1])/
                (double)(tempTable[i][0] - tempTable[i-1][0])
        }
    }
}