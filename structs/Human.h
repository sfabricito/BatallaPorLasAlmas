// Imports
#include <iostream>
#include <chrono> // Library for dates in C++
using namespace std;

// Prototypes
struct Human;

// Variables
string namesSpanish[] = {
        "Liam", "Noah", "Oliver", "James", "Elijah", "William", "Henry", "Lucas",
        "Benjamin", "Theodore", "Mateo", "Levi", "Sebastian", "Daniel", "Jack", "Michael",
        "Alexander", "Owen", "Asher", "Samuel", "Ethan", "Leo", "Jackson", "Mason",
        "Ezra", "John", "Hudson", "Luca", "Aiden", "Joseph", "David", "Jacob", "Logan", "Luke",
        "Julian", "Gabriel", "Grayson", "Wyatt", "Matthew", "Maverick", "Dylan", "Isaac", "Elias",
        "Anthony", "Thomas", "Jayden", "Carter", "Santiago", "Ezekiel", "Charles", "Josiah", "Caleb",
        "Cooper", "Lincoln", "Miles", "Christopher", "Nathan", "Isaiah", "Kai", "Joshua", "Andrew",
        "Angel", "Adrian", "Cameron", "Nolan", "Waylon", "Jaxon", "Roman", "Eli", "Wesley", "Aaron",
        "Ian", "Christian", "Ryan", "Leonardo", "Brooks", "Axel", "Walker", "Jonathan", "Easton",
        "Everett", "Weston", "Bennett", "Robert", "Jameson", "Landon", "Silas", "Jose", "Beau", "Micah",
        "Colton", "Jordan", "Jeremiah", "Parker", "Greyson", "Rowan", "Adam", "Nicholas", "Theo",
        "Xavier", "Hunter", "Dominic", "Jace", "Gael", "River", "Thiago", "Kayden", "Damian", "August",
        "Carson", "Austin", "Myles", "Amir", "Declan", "Emmett", "Ryder", "Luka", "Connor", "Jaxson",
        "Milo", "Enzo", "Giovanni", "Vincent", "Diego", "Luis", "Archer", "Harrison", "Kingston",
        "Atlas", "Jasper", "Sawyer", "Legend", "Lorenzo", "Evan", "Jonah", "Chase", "Bryson", "Adriel",
        "Nathaniel", "Arthur", "Juan", "George", "Cole", "Zion", "Jason", "Ashton", "Carlos",
        "Calvin", "Brayden", "Elliot", "Rhett", "Emiliano", "Ace", "Jayce", "Graham", "Max", "Braxton",
        "Leon", "Ivan", "Hayden", "Jude", "Malachi", "Dean", "Tyler", "Jesus", "Zachary", "Kaiden",
        "Elliott", "Arlo", "Emmanuel", "Ayden", "Bentley", "Maxwell", "Amari", "Ryker", "Finn", "Antonio",
        "Charlie", "Maddox", "Justin", "Judah", "Kevin", "Dawson", "Matteo", "Miguel", "Zayden",
        "Camden", "Messiah", "Alan", "Alex", "Nicolas", "Felix", "Alejandro", "Jesse", "Beckett",
        "Matias", "Tucker", "Emilio", "Xander", "Knox", "Oscar", "Beckham", "Timothy", "Abraham",
        "Andres", "Gavin", "Brody", "Barrett", "Hayes", "Jett", "Brandon", "Joel", "Victor", "Peter",
        "Abel", "Edward", "Karter", "Patrick", "Richard", "Grant", "Avery", "King", "Caden", "Adonis",
        "Riley", "Tristan", "Kyrie", "Blake", "Eric", "Griffin", "Malakai", "Rafael", "Israel", "Tate",
        "Lukas", "Nico", "Marcus", "Stetson", "Javier", "Colt", "Omar", "Simon", "Kash", "Remington",
        "Jeremy", "Louis", "Mark", "Lennox", "Callum", "Kairo", "Nash", "Kyler", "Dallas", "Crew",
        "Preston", "Paxton", "Steven", "Zane", "Kaleb", "Lane", "Phoenix", "Paul", "Cash", "Kenneth",
        "Bryce", "Ronan", "Kaden", "Maximiliano", "Walter", "Maximus", "Emerson", "Hendrix", "Jax",
        "Atticus", "Zayn", "Tobias", "Cohen", "Aziel", "Kayson", "Rory", "Brady", "Finley", "Holden",
        "Jorge", "Malcolm", "Clayton", "Niko", "Francisco", "Josue", "Brian", "Bryan", "Cade", "Colin",
        "Andre", "Cayden", "Aidan", "Muhammad", "Derek", "Ali", "Elian", "Bodhi", "Cody", "Jensen",
        "Damien", "Martin", "Cairo", "Ellis", "Khalil", "Otto", "Zander", "Dante", "Ismael", "Angelo",
        "Brantley", "Manuel", "Colson", "Cruz", "Tatum", "Jaylen", "Jaden", "Erick", "Cristian", "Romeo",
        "Milan", "Reid", "Cyrus", "Leonel", "Joaquin", "Ari", "Odin", "Orion", "Ezequiel", "Gideon",
        "Daxton", "Warren", "Casey", "Anderson", "Spencer", "Karson", "Eduardo", "Chance", "Fernando",
        "Raymond", "Bradley", "Cesar", "Wade", "Prince", "Julius", "Dakota", "Kade", "Koa", "Raiden",
        "Callan", "Hector", "Onyx", "Remy", "Ricardo", "Edwin", "Stephen", "Kane", "Saint", "Titus",
        "Desmond", "Killian", "Sullivan", "Mario", "Jay", "Kamari", "Luciano", "Royal", "Zyaire",
        "Marco", "Wilder", "Russell", "Nasir", "Rylan", "Archie", "Jared", "Gianni", "Kashton",
        "Kobe", "Sergio", "Travis", "Marshall", "Iker", "Briggs", "Gunner", "Apollo", "Bowen",
        "Baylor", "Sage", "Tyson", "Kyle", "Oakley", "Malik", "Mathias", "Sean", "Armani", "Aubrey",
        "Summer", "Ashley", "Andrea", "Isabel", "Oakley", "Olive", "Oaklynn", "Ember", "Kaylee",
        "Georgia", "Juliette", "Anastasia", "Genevieve", "Katherine", "Blakely", "Reese", "Amaya",
        "Emerson", "Brianna", "June", "Alani", "Lainey", "Arianna", "Rosalie", "Sara", "Jasmine",
        "Ruth", "Adalyn", "Ada", "Bailey", "Ariella", "Wren", "Myla", "Khloe", "Callie", "Elsie",
        "Alexandra", "Ryleigh", "Faith", "Norah", "Margot", "Zuri", "Journee", "Aspen", "Gemma",
        "Kylie", "Molly", "Blake", "Zara", "Alaina", "Alana", "Brynlee", "Amy", "Annie", "Saylor",
        "Ana", "Amira", "Kimberly", "Noelle", "Kamila", "Morgan", "Phoebe", "Harmony", "Sutton",
        "Taylor", "Finley", "Lilah", "Juliana", "Lila", "Londyn", "Kailani", "Vera", "Kaia",
        "Angela", "Hallie", "Diana", "Lennon", "Presley", "Arabella", "Aliyah", "Lilly", "Milani",
        "Jordyn", "Camille", "Ariel", "Aubree", "Selena", "Sawyer", "Nyla", "Delaney", "Mariana",
        "Rachel", "Adaline", "Leila", "Collins", "Lia", "Octavia", "Kali", "Lena", "Kiara", "Kaylani",
        "Elaina", "Daniela", "Leia", "Gracie", "Dakota", "Elise", "Hope", "Harlow", "Lola", "Stevie",
        "Malia", "Miriam", "Alora", "Gia", "Evangeline", "Brooke", "Lilith", "Sydney", "Ophelia",
        "Alayna", "Tatum", "Evie", "Rowan", "Marley", "Daphne", "Kayla", "Dahlia", "Lucille", "Blair",
        "Adelaide", "Wrenley", "Haven", "Teagan", "Adelyn", "Alyssa", "Payton", "Jane", "Mckenna",
        "Celeste", "Juliet", "Palmer", "Maggie", "Rebecca", "London", "Noa", "Samara", "Thea",
        "Kendall", "Mya", "Talia", "Winter", "Angelina", "Vivienne", "Esme", "Laila", "Nina", "Trinity",
        "Vanessa", "Mabel", "Camilla", "Jocelyn", "Journey", "Paige", "Phoenix", "Amina", "Alivia",
        "Amari", "Joanna", "Nicole", "Annabelle", "Raegan", "Aitana", "Julianna", "Lauren", "Catherine",
        "Adriana", "Madilyn", "Harley", "Tessa", "Evelynn", "Elianna", "Rory", "Dream", "Nayeli",
        "Poppy", "Gabriela", "Jayla", "Cataleya", "Celine", "Hayden", "Shiloh", "Mariah", "Charlee",
        "Maisie", "Regina", "Adelynn", "Briella", "Giselle", "Fatima", "Danna", "Alessia", "Mckenzie",
        "Wynter", "Fiona", "Brooklynn", "Gracelynn", "Luciana", "Alexis", "Everlee", "Laura", "Selah",
        "Reign", "Alayah", "Rosemary", "Lilliana", "Ariyah", "Heidi", "Esmeralda", "Logan", "Amora",
        "Kalani", "Leighton", "Cali", "Melissa", "Aniyah", "Izabella", "Michelle", "Raelyn", "Alessandra",
        "Viviana", "Madeleine", "Arielle", "Serena", "Francesca", "Brynn", "Gwendolyn", "Kira", "Destiny",
        "Elle", "Makayla", "Alaya", "Malani", "Willa", "Saige", "Makenna", "Remington", "Demi", "Adelina",
        "Raya", "Astrid", "Azalea", "Veronica", "Meadow", "Anaya", "Elisa", "Raven", "Alexandria",
        "Hattie", "Alicia", "Sabrina", "Gracelyn", "Matilda", "Skye", "Annalise", "Frances", "Miracle",
        "Maia", "Helen", "Lana", "Daleyza", "Rosie", "Charli", "Bianca", "Royalty", "Sarai", "Amiyah",
        "Nylah", "Aylin", "Maryam", "Scarlet", "Antonella", "Sylvia", "Sylvie", "Nadia", "Ari",
        "Lexi", "Mylah", "Julieta", "Lorelei", "Avianna", "Armani", "Camryn", "Emely", "Rylie",
        "Colette", "Daniella", "Liana", "Brinley", "Kate", "Salem", "Marlee", "Alison", "Carmen",
        "Felicity", "Fernanda", "Holly", "Ariah", "Aisha", "Kora", "Amanda", "Ailani", "Elaine",
        "Emory", "Joy", "Oaklee", "Lyric", "Madelynn", "Haisley", "Allie", "Helena", "Danielle",
        "Katalina", "Carolina", "Zariah", "Navy", "Cassidy", "Lorelai", "Stephanie", "Alma", "Mira",
        "Legacy", "Jolene", "Anya", "Dorothy", "Paris", "Yaretzi", "Aurelia", "Maddison", "Renata",
        "Jimena", "Xiomara", "Itzel", "Heaven", "Lyra", "Estella", "Gabrielle", "Jennifer"
    };
string lastNames[] = {
        "Castillo",
        "Montenegro",
        "Valencia",
        "Delgado",
        "Rivera",
        "Serrano",
        "Alarcón",
        "Mendoza",
        "Vargas",
        "Herrera",
        "Roman",
        "Paredes"
    };
string countries[] = {
        "United States",
        "Canada",
        "Australia",
        "France",
        "Germany",
        "Brazil",
        "Argentina",
        "Spain",
        "Italy",
        "Singapore",
        "Sweden",
        "Belgium",
        "New Zealand",
        "Monaco"
    };
string beliefs[] = {
        "Christianity",
        "Islam",
        "Hinduism",
        "Buddhism",
        "Atheism"
    };
string professions[] = {
        "Doctor",
        "Teacher",
        "Engineer",
        "Lawyer",
        "Architect",
        "Accountant",
        "Chef",
        "Mechanic",
        "Actor",
        "Pilot",
        "Entrepreneur",
        "Farmer"
    };
string socialMedia[] = {
        "Twiter", "Instagram", "Netflix", "Tinder", "Facebook",
        "Linkedin", "Pinterest"
    };

// Structs
struct Human{
    int id;
    string name;
    string lastName;
    string country;
    string belief;
    string profession;
    time_t birthday;
    string sins[100];
    Human * friends[100];
    int socialMediaPriority[7];
};

// Functions