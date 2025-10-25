#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// Function to present a question and record the user's answer
bool askQuestion(const string& question, const string& answer, const vector<string>& incorrectAnswers) {
    cout << question << endl;
    cout << "A) " << answer << endl;
    cout << "B) " << incorrectAnswers[0] << endl;
    cout << "C) " << incorrectAnswers[1] << endl;
    cout << "D) " << incorrectAnswers[2] << endl;

    char userAnswer;
    cout << "Your answer: ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer); // Convert the answer to uppercase

    return userAnswer == 'A';
}

int main() {
    // Define questions, correct answers, and incorrect answers
    map<string, string> questions;
   
    questions["What is the Gilded Age?"] = "A time of rapid industrialization and economic growth.";
    questions["What is a trust in the context of the late 19th century?"] = "A form of business organization to reduce competition.";
    questions["What is finance capitalism?"] = "An economic system emphasizing investment, stock markets, and banking.";
    questions["What is Social Darwinism?"] = "A theory of evolution applied to society.";
    questions["What was the Jim Crow system?"] = "A system of racial segregation and discrimination.";
    questions["What did the Woman's Christian Temperance Union advocate for?"] = "Prohibition of alcohol, women's suffrage, and social reform.";
    questions["What is civil service reform?"] = "Efforts to professionalize and depoliticize government employment.";
    questions["What was the purpose of the Interstate Commerce Commission (ICC)?"] = "To regulate interstate commerce.";
    questions["What did the Sherman Antitrust Act aim to prohibit?"] = "Anticompetitive business practices and monopolies.";
    questions["What was the New South movement?"] = "A movement emphasizing industrialization and a departure from the agrarian past.";
    questions["What is the Gospel of Wealth?"] = "An essay advocating philanthropy by the wealthy.";
    questions["What is laissez-faire?"] = "An economic philosophy advocating minimal government intervention in business.";
    questions["What is the spoils system?"] = "A system of awarding government contracts.";
    questions["Who wrote the essay 'The Gospel of Wealth'?"] = "Andrew Carnegie.";
    questions["Who was known for aggressive business practices, including stock manipulation, during the late 19th century?"] = "Jay Gould.";
    questions["Which company dominated the oil industry through horizontal integration?"] = "Standard Oil Company.";
    questions["What is horizontal integration?"] = "A strategy involving the consolidation of control over industries.";
    questions["What are holding companies used for?"] = "To control other businesses.";
    questions["What major steel corporation was formed in 1901?"] = "United States Steel.";
    questions["What is an oligopoly?"] = "A market structure characterized by a few large firms.";
    questions["Who founded the National Association for the Advancement of Colored People (NAACP) in 1909?"] = "W. E. B. Du Bois.";
    questions["What is the civil service exam?"] = "A merit-based examination system for government employment.";
    questions["What is political mudslinging?"] = "A practice of making malicious attacks on political opponents.";
    questions["What did the Supreme Court case Plessy vs. Ferguson establish?"] = "The doctrine of 'separate but equal.'";
    questions["What was the Progressive movement?"] = "A social reform movement.";
    questions["What is muckraking?"] = "A form of investigative journalism exposing social and political issues.";
    questions["Who was the founder of Carnegie Steel?"] = "Andrew Carnegie.";
    questions["What is vertical integration?"] = "A business model controlling a product's lifecycle from production to distribution.";
    questions["What did the Standard Oil Company dominate?"] = "The oil industry.";
    questions["What is a holding company?"] = "A company that owns other companies' stock.";
    questions["What was the purpose of the Interstate Commerce Commission (ICC)?"] = "To oversee and regulate railroad rates and practices.";
    questions["What did the Sherman Antitrust Act aim to prohibit?"] = "Monopolistic practices and anticompetitive business behavior.";

 map<string, vector<string>> incorrectAnswers;
    incorrectAnswers["What is the Gilded Age?"] = {
        "A period of political revolution.",
        "The era of the American Civil War.",
        "A period of cultural stagnation."
    };
    incorrectAnswers["What is a trust in the context of the late 19th century?"] = {
        "A legal document.",
        "A philanthropic organization.",
        "A government agency."
    };
    incorrectAnswers["What is finance capitalism?"] = {
        "An economic system where the government controls all financial institutions.",
        "An economic system focused on barter trade.",
        "An economic system without banks or financial institutions."
    };
    incorrectAnswers["What is Social Darwinism?"] = {
        "A scientific theory about natural selection.",
        "A political ideology advocating for social equality.",
        "A form of government."
    };
    incorrectAnswers["What was the Jim Crow system?"] = {
        "A legal system for corporate regulation.",
        "A system of land distribution in the West.",
        "A form of religious worship."
    };
    incorrectAnswers["What did the Woman's Christian Temperance Union advocate for?"] = {
        "The promotion of alcohol consumption.",
        "Freedom of speech.",
        "Tax reform."
    };
    incorrectAnswers["What is civil service reform?"] = {
        "A reform of the military.",
        "Reform of the criminal justice system.",
        "Reform of the education system."
    };
    incorrectAnswers["What was the purpose of the Interstate Commerce Commission (ICC)?"] = {
        "To regulate immigration.",
        "To regulate the stock market.",
        "To regulate foreign policy."
    };
    incorrectAnswers["What did the Sherman Antitrust Act aim to prohibit?"] = {
        "Tax evasion.",
        "Political corruption.",
        "Labor strikes."
    };
    incorrectAnswers["What was the New South movement?"] = {
        "A movement advocating for the preservation of Southern traditions.",
        "A movement advocating for the abolition of slavery.",
        "A movement promoting isolationism."
    };
    incorrectAnswers["What is the Gospel of Wealth?"] = {
        "A religious text.",
        "A political manifesto.",
        "A novel."
    };
    incorrectAnswers["What is laissez-faire?"] = {
        "A type of cuisine.",
        "A French art movement.",
        "A form of dance."
    };
    incorrectAnswers["What is the spoils system?"] = {
        "A political strategy.",
        "A merit-based hiring system.",
        "A system of government taxation."
    };
    incorrectAnswers["Who wrote the essay 'The Gospel of Wealth'?"] = {
        "Samuel Clemens.",
        "John D. Rockefeller.",
        "Ida Tarbell."
    };
    incorrectAnswers["Who was known for aggressive business practices, including stock manipulation, during the late 19th century?"] = {
        "John Pierpont Morgan.",
        "Andrew Carnegie.",
        "Susan B. Anthony."
    };
    incorrectAnswers["Which company dominated the oil industry through horizontal integration?"] = {
        "U.S. Steel.",
        "Carnegie Steel.",
        "The Intercontinental Oil Corporation."
    };
    incorrectAnswers["What is horizontal integration?"] = {
        "A business model controlling a product's lifecycle from production to distribution.",
        "A method of regulating competition.",
        "A marketing technique."
    };
    incorrectAnswers["What are holding companies used for?"] = {
        "To hold government assets.",
        "To manage charitable foundations.",
        "To oversee law enforcement agencies."
    };
    incorrectAnswers["What major steel corporation was formed in 1901?"] = {
        "Standard Oil.",
        "Carnegie Steel.",
        "International Steel Co."
    };
    incorrectAnswers["What is an oligopoly?"] = {
        "A form of government.",
        "A type of antitrust law.",
        "A term used in sociology."
    };
    incorrectAnswers["Who founded the National Association for the Advancement of Colored People (NAACP) in 1909?"] = {
        "Andrew Carnegie.",
        "John D. Rockefeller.",
        "Susan B. Anthony."
    };
    incorrectAnswers["What is the civil service exam?"] = {
        "A test for military service.",
        "A qualifying exam for lawyers.",
        "A test for citizenship."
    };
    incorrectAnswers["What is political mudslinging?"] = {
        "A form of pottery.",
        "A style of political speeches.",
        "A method of campaign fundraising."
    };
    incorrectAnswers["What did the Supreme Court case Plessy vs. Ferguson establish?"] = {
        "The doctrine of 'equal rights for all.'",
        "The end of racial segregation.",
        "The end of political corruption."
    };
    incorrectAnswers["What was the Progressive movement?"] = {
        "A movement advocating for conservative values.",
        "A political party.",
        "A literary movement."
    };
    incorrectAnswers["What is muckraking?"] = {
        "A type of farm equipment.",
        "A political ideology.",
        "A method of government regulation."
    };
    incorrectAnswers["Who was the founder of Carnegie Steel?"] = {
        "John D. Rockefeller.",
        "Ida Tarbell.",
        "Samuel Clemens."
    };
    incorrectAnswers["What is vertical integration?"] = {
        "A type of political system.",
        "A form of social organization.",
        "A strategy for labor unions."
    };
    incorrectAnswers["What did the Standard Oil Company dominate?"] = {
        "The steel industry.",
        "The automobile industry.",
        "The telecommunications industry."
    };
    incorrectAnswers["What is a holding company?"] = {
        "A company that holds government assets.",
        "A type of bank.",
        "A nonprofit organization."
    };
    incorrectAnswers["What was the purpose of the Interstate Commerce Commission (ICC)?"] = {
        "To regulate the airline industry.",
        "To regulate the healthcare industry.",
        "To manage foreign relations."
    };
    incorrectAnswers["What did the Sherman Antitrust Act aim to prohibit?"] = {
        "Tax evasion by wealthy individuals.",
        "Labor unions.",
        "Political corruption."
    };


    int correctAnswers = 0;
    int totalQuestions = questions.size();

    // Loop through the questions and ask them one by one
    for (const auto& [question, answer] : questions) {
        if (askQuestion(question, answer, incorrectAnswers[question])) { // Use 'question' as the index
            cout << "Correct!" << endl;
            correctAnswers++;
        } else {
            cout << "Incorrect. The correct answer is A) " << answer << "." << endl;
        }

        cout << endl;
    }

    // Calculate and display the user's score
    double score = (static_cast<double>(correctAnswers) / totalQuestions) * 100;
    cout << "Your score: " << score << "%" << endl;

    // Save the results to a file
    ofstream outfile("historytest.txt");
    for (const auto& [question, answer] : questions) {
        outfile << question << endl;
        outfile << "Correct Answer: A) " << answer << endl;
        outfile << "Incorrect Answers:" << endl;
        for (const string& incorrectAnswer : incorrectAnswers[question]) { // Use 'question' as the index
            outfile << "B) " << incorrectAnswer << endl;
        }
        outfile << endl;
    }
    outfile.close();

    // Display the contents of the saved file
    ifstream infile("historytest.txt");
    string line;
    while (getline(infile, line)) {
        cout << line << endl;
    }
    infile.close();

    cout << "Press enter to exit...";
    cin.ignore();
    cin.get();
    return 0;
}