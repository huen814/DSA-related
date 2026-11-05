#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATIONS 10

typedef int MembershipSet[MAX_STATIONS];
typedef enum { FALSE = 0, TRUE = 1 } Boolean;

// Function prototypes
void initMembershipSet(MembershipSet set);
void displayMembershipSet(MembershipSet set, const char* membershipType);
void occupyStation(MembershipSet set, int stationNum);
void freeStation(MembershipSet set, int stationNum);
Boolean isStationOccupied(MembershipSet set, int stationNum);

// Set operations for membership analysis
MembershipSet* getBusyStations(MembershipSet regular, MembershipSet premium);
MembershipSet* getUpgradeOpportunities(MembershipSet regular, MembershipSet vip);
MembershipSet* getPromotionStations(MembershipSet premium);
Boolean checkServiceConsistency(MembershipSet vip, MembershipSet premium);
MembershipSet* getGeneralOccupancy(MembershipSet regular, MembershipSet premium, MembershipSet vip);
MembershipSet* getBasicServiceAreas(MembershipSet regular, MembershipSet premium, MembershipSet vip);

// Helper function
void printAnalysis(const char* analysisName, MembershipSet* result, Boolean isBoolean, Boolean boolResult);

int main() {
    printf("=== COMPREHENSIVE TEST SUITE FOR GAMING CAFÃ‰ SYSTEM ===\n\n");
    
    // ========== TEST 1: Basic Function Tests ==========
    printf("TEST 1: Basic Function Tests\n");
    printf("================================\n");
    
    MembershipSet testSet;
    initMembershipSet(testSet);
    
    printf("After initialization:\n");
    displayMembershipSet(testSet, "Test");
    printf("\n// EXPECTED: Test Members: [0][0][0][0][0][0][0][0][0][0]\n\n");
    
    occupyStation(testSet, 3);
    occupyStation(testSet, 7);
    printf("After occupying stations 3 and 7:\n");
    displayMembershipSet(testSet, "Test");
    printf("\n// EXPECTED: Test Members: [0][0][0][1][0][0][0][1][0][0]\n");
    printf("Station 3 occupied? %s (EXPECTED: YES)\n", isStationOccupied(testSet, 3) ? "YES" : "NO");
    printf("Station 5 occupied? %s (EXPECTED: NO)\n", isStationOccupied(testSet, 5) ? "YES" : "NO");
    
    freeStation(testSet, 3);
    printf("After freeing station 3:\n");
    displayMembershipSet(testSet, "Test");
    printf("\n// EXPECTED: Test Members: [0][0][0][0][0][0][0][1][0][0]\n\n");
    
    // ========== TEST 2: Story Problem Scenario ==========
    printf("TEST 2: Original Story Problem Scenario\n");
    printf("==========================================\n");
    
    MembershipSet regularMembers, premiumMembers, vipMembers;
    
    initMembershipSet(regularMembers);
    initMembershipSet(premiumMembers);
    initMembershipSet(vipMembers);
    
    occupyStation(regularMembers, 1);
    occupyStation(regularMembers, 3);
    occupyStation(regularMembers, 5);
    occupyStation(regularMembers, 7);
    occupyStation(regularMembers, 9);
    
    occupyStation(premiumMembers, 2);
    occupyStation(premiumMembers, 4);
    occupyStation(premiumMembers, 6);
    occupyStation(premiumMembers, 7);
    occupyStation(premiumMembers, 8);
    
    occupyStation(vipMembers, 7);
    occupyStation(vipMembers, 8);
    occupyStation(vipMembers, 9);
    
    printf("\n--- Current Status ---\n");
    displayMembershipSet(regularMembers, "Regular");
    displayMembershipSet(premiumMembers, "Premium");
    displayMembershipSet(vipMembers, "VIP");
    printf("\n");
    
    // Test set operations
    MembershipSet* busyStations = getBusyStations(regularMembers, premiumMembers);
    printAnalysis("Busy Stations (Regular AND Premium)", busyStations, FALSE, FALSE);

    MembershipSet* upgradeOps = getUpgradeOpportunities(regularMembers, vipMembers);
    printAnalysis("Upgrade Opportunities (Regular NOT VIP)", upgradeOps, FALSE, FALSE);

    MembershipSet* promoStations = getPromotionStations(premiumMembers);
    printAnalysis("Promotion Stations (No Premium)", promoStations, FALSE, FALSE);

    Boolean consistent = checkServiceConsistency(vipMembers, premiumMembers);
    printAnalysis("Service Consistency (VIP subset of Premium?)", NULL, TRUE, consistent);

    MembershipSet* generalOcc = getGeneralOccupancy(regularMembers, premiumMembers, vipMembers);
    printAnalysis("General Occupancy (Any member type)", generalOcc, FALSE, FALSE);

    MembershipSet* basicAreas = getBasicServiceAreas(regularMembers, premiumMembers, vipMembers);
    printAnalysis("Basic Service Areas (ONLY Regular)", basicAreas, FALSE, FALSE);

    free(busyStations);
    free(upgradeOps);
    free(promoStations);
    free(generalOcc);
    free(basicAreas);

    return 0;
}

void initMembershipSet(MembershipSet set) {
    
    // TODO: Set all stations to 0
    for(int i = 0; i < MAX_STATIONS;i++){
        set[i] = 0;
    }
}

void displayMembershipSet(MembershipSet set, const char* membershipType) {
    // TODO: Format: "\n[membershipType] Members: [0][1]..."

    printf("\n%s Members: ",membershipType);

    for(int i = 0; i < MAX_STATIONS;i++){
        printf("[%d]",set[i]);
    }
}

void occupyStation(MembershipSet set, int stationNum) {
    // TODO: Set stationNum to 1
    set[stationNum] = 1;
}

void freeStation(MembershipSet set, int stationNum) {
    // TODO: Set stationNum to 0
    set[stationNum] = 0;
}

Boolean isStationOccupied(MembershipSet set, int stationNum) {
    // TODO: Return TRUE if occupied, FALSE otherwise

    if(set[stationNum]==1){
        return TRUE;
    }
    return FALSE;
}

MembershipSet* getBusyStations(MembershipSet regular, MembershipSet premium) {
    // TODO: Allocate MembershipSet, station occupied iff regular[i] && premium[i]
    
    MembershipSet *occupied = malloc(sizeof(MembershipSet));

    for(int i = 0; i < MAX_STATIONS;i++){
        (*occupied)[i] = regular[i] && premium[i];
    }

    return occupied;
}

MembershipSet* getUpgradeOpportunities(MembershipSet regular, MembershipSet vip) {
    
    MembershipSet *upgrade = malloc(sizeof(MembershipSet));

    for(int i = 0;i < MAX_STATIONS;i++){
        (*upgrade)[i] = !vip[i] && regular[i];
    }
    return upgrade;
}

MembershipSet* getPromotionStations(MembershipSet premium) {
    // TODO: !premium[i]

    MembershipSet *promotion = malloc(sizeof(MembershipSet));
    for(int i = 0; i < MAX_STATIONS;i++){
        (*promotion)[i] = !premium[i];
    }
    return promotion;
}

Boolean checkServiceConsistency(MembershipSet vip, MembershipSet premium) {
    // TODO: Check if VIP is a subset of Premium (return TRUE if all VIP are Premium)


    for(int i = 0; i < MAX_STATIONS; i++){
        if(vip[i] && !premium[i]){ return FALSE;
        }
    }
    
    return TRUE;
}

MembershipSet* getGeneralOccupancy(MembershipSet regular, MembershipSet premium, MembershipSet vip) {
    // TODO: regular[i] || premium[i] || vip[i]

    MembershipSet *general = malloc(sizeof(MembershipSet));

    for(int i = 0; i < MAX_STATIONS;i++){
        (*general)[i] = regular[i] || premium[i] || vip[i];
    }

    return general;
}

MembershipSet* getBasicServiceAreas(MembershipSet regular, MembershipSet premium, MembershipSet vip) {
    // TODO: regular[i] && !premium[i] && !vip[i]

    MembershipSet *basic = malloc(sizeof(MembershipSet));

    for(int i = 0; i < MAX_STATIONS;i++){
        (*basic)[i] = regular[i] && !premium[i] && !vip[i];
    }

    return basic;
}

void printAnalysis(const char* analysisName, MembershipSet* result, Boolean isBoolean, Boolean boolResult) {
    printf("\n%s:\n", analysisName);
    if (isBoolean) {
        printf("   Result: %s\n", boolResult ? "YES" : "NO");
    } else if (result != NULL) {
        printf("   Stations: ");
        Boolean hasAny = FALSE;
        for (int i = 0; i < MAX_STATIONS; i++) {
            if ((*result)[i] == 1) {
                printf("%d ", i);
                hasAny = TRUE;
            }
        }
        if (!hasAny) {
            printf("None");
        }
        printf("\n");
    } else {
        printf("   Error: Could not perform analysis\n");
    }
}
