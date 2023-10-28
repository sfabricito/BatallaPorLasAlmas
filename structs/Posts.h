#include "Human.h"

// Methods
void postOnSocialMedia(Human* human, int platformIndex) {
    if (platformIndex >=0 && platformIndex < 7) {
        // Determine the social media platform based on platformIndex.
        string platformName;

        switch (platformIndex ) {
            case 0:
                platformName = "Twitter";
                break;
            case 1:
                platformName = "Instagram";
                break;
            case 2:
                platformName = "Netflix";
                break;
            case 3:
                platformName = "Tinder";
                break;
            case 4:
                platformName = "Facebook";
                break;
            case 5:
                platformName = "LinkedIn";
                break;
            case 6:
                platformName = "Pinterest";
                break;
        }

        // Simulate posting content on the selected platform.
        cout << "Posted on " << platformName << endl;

        // Iterate through the friends of the human who will see the post.
        for (int i = 0; i < 100; i++) {
            if (human->friends[i] != nullptr) {
                Human* socialFriend = human->friends[i];

                // Find the maximum priority value among all platforms for this friend.
                int maxPriority = socialFriend->socialMediaPriority[0];
                for (int j = 1; j < 7; j++) {
                    if (j != platformIndex && socialFriend->socialMediaPriority[j] > maxPriority) {
                        maxPriority = socialFriend->socialMediaPriority[j];
                    }
                }

                // Calculate the order of preference for this friend based on the maximum value.
                int orderOfPreference = 1;
                for (int j = 0; j < 7; j++) {
                    if (j != platformIndex && socialFriend->socialMediaPriority[j] < maxPriority) {
                        orderOfPreference++;
                    }
                }

                // Calculate the number of sins to add based on the order of preference.
                int sinsToAdd = 8 - orderOfPreference;

                // Add sins to the friend.
                if (sinsToAdd > 0) {
                    socialFriend->sins[platformIndex] += sinsToAdd;
                    cout << "Friend " << socialFriend->id << " saw the post on " << platformName << " and added " << sinsToAdd << " sins." << endl;
                }
            }
        }
    } else {
        // Handle invalid platformIndex.
        cout << "Invalid platform index." << endl;
    }
}


void postOnSocialMediaByID(int humanID, int platformIndex) {
    Human* human = searchHumanByID(humanID);
    if (human != nullptr) {
        postOnSocialMedia(human, platformIndex);  
    } else {
        cout << "Human with ID " << humanID << " not found." << endl;
    }
}



void postByReligion(string religion) {//Modificarlo para verificar que este vivo
    for (int i = 0; i < humanitySize; i++) {
        if (humanity[i] != nullptr && humanity[i]->belief == religion) {
            int favoritePlatformIndex = 0; // Initialize with the first platform.
            int maxPriority = humanity[i]->socialMediaPriority[0];

            // Determine the favorite platform.
            for (int j = 1; j < 7; j++) {
                if (humanity[i]->socialMediaPriority[j] > maxPriority) {
                    maxPriority = humanity[i]->socialMediaPriority[j];
                    favoritePlatformIndex = j;
                }
            }

            postOnSocialMedia(humanity[i], favoritePlatformIndex);
        }
    }
}


void postByProfession(string profession, int n) {
    for (int i = 0; i < humanitySize; i++) {
        if (humanity[i] != nullptr && humanity[i]->profession == profession) {
            for (int j = 0; j < n; j++) {
                if (j < 7) {
                    int favoritePlatformIndex = j; // j platform index.
                    postOnSocialMedia(humanity[i], favoritePlatformIndex);
                }
            }
        }
    }
}


void postByFamily(string country, string lastName, int n) {
    for (int i = 0; i < humanitySize; i++) {
        if (humanity[i] != nullptr && humanity[i]->country == country && humanity[i]->lastName == lastName) {
            for (int j = 0; j < n; j++) {
                if (j < 7) {
                    int favoritePlatformIndex = j; // j platform index.
                    postOnSocialMedia(humanity[i], favoritePlatformIndex);
                }
            }
        }
    }
}