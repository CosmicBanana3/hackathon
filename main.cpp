#include <iostream>
#include "raylib.h"
#include "button.h"
#include <vector>
#include <string>


//The Class Button needs, x pos, y pos, width, heigh,  text, normal color, hover color 


//WARNING: a lot of spaghetti, its logic is short(ish) for a question, but this has 6 :/

/*AI Usage: The AI usage in this is in the making process of the button, since raylib has multiple events we didnt kknow where to start.
The button was also probally the most importiant thing in this project since eveyting needed a button to access.
We wanted to get that correct so it wouldnt hinder the other things that were going to be built on top of it.
Another use of AI was debugging, but mostly becasue raylib is written in c and not in cpp, so some conflict came up when the c library tried to read cpp code.
*/

//Side note: the code works on windows, but i dontk know about mac :/


int main(){

InitWindow(1920,1080,"The big beans");
Color StarBlue = {235, 245, 255, 255};
Color SummerYellow = {250, 251, 114, 255};
Color WinterBlue = {207, 238, 253, 255};
Color SpringGreen = {158, 203, 145, 255};
int Current_tab = 0;
float center_H = GetScreenHeight()/2.0f;
int TopButtons = center_H - 200;
int BottomButtons = center_H + 200;
Vector2 StemButtonSize = {160, 60};
vector<int> Stem_button_x_spacing = {220, 380, 540, 700, 860, 1020};
int QuizFontSize = 24;
    
vector<Button> StemButtons;

StemButtons.push_back(Button(Stem_button_x_spacing[0], TopButtons, StemButtonSize.x, StemButtonSize.y, "Summer 1", {255, 238, 150, 255}, {225, 208, 120, 255}));
StemButtons.push_back(Button(Stem_button_x_spacing[1], BottomButtons, StemButtonSize.x, StemButtonSize.y, "Winter 1", {255, 238, 150, 255}, {225, 208, 120, 255}));
StemButtons.push_back(Button(Stem_button_x_spacing[2], TopButtons, StemButtonSize.x, StemButtonSize.y, "Summer 2", {255, 238, 150, 255}, {225, 208, 120, 255}));
StemButtons.push_back(Button(Stem_button_x_spacing[3], BottomButtons, StemButtonSize.x, StemButtonSize.y, "Winter 2", {255, 238, 150, 255}, {225, 208, 120, 255}));
StemButtons.push_back(Button(Stem_button_x_spacing[4], TopButtons, StemButtonSize.x, StemButtonSize.y, "Spring 1", {255, 238, 150, 255}, {225, 208, 120, 255}));
StemButtons.push_back(Button(Stem_button_x_spacing[5], BottomButtons, StemButtonSize.x, StemButtonSize.y, "Summer 3", {255, 238, 150, 255}, {225, 208, 120, 255}));

bool Summer1Passed = false;
bool Winter1Passed = false;
bool Summer2Passed = false;
bool Winter2Passed = false;
bool Spring1Passed = false;
bool Summer3Passed = false;

Button back_button = {(float)GetScreenWidth() - 150.0f, (float)GetScreenHeight() - 80.0f, 100, 50, "Back", {128, 128, 128, 255}, {98, 98, 98, 255}};

float Star_TimeHolder = 0.801f;
vector<Vector2> stars;
for (int i = 0; i < 250; i++){
    float x = GetRandomValue(0, GetScreenWidth());
    float y = GetRandomValue(0, GetScreenHeight());
    Vector2 hold = {x,y};
    stars.push_back(hold);
}
vector<int> Star_Radius;
bool TakingQuiz = false;

string QuizResult = "";

Button StartQuizButton(100, 260, 220, 60, "Take Quiz", { 173, 235, 179, 255 }, { 143, 205, 149, 255 });


vector<Button> QuizChoices_Summer1;
QuizChoices_Summer1.push_back(Button(100, 280, 900, 55, "A) Commercial tech investments",     LIGHTGRAY, SKYBLUE));
QuizChoices_Summer1.push_back(Button(100, 355, 900, 55, "B) The 1956 Dartmouth Workshop and early DARPA funding", LIGHTGRAY, SKYBLUE));
QuizChoices_Summer1.push_back(Button(100, 430, 900, 55, "C) The use of AI systems in real situations",    LIGHTGRAY, SKYBLUE));
QuizChoices_Summer1.push_back(Button(100, 505, 900, 55, "D) Joke Answer",  LIGHTGRAY, SKYBLUE));

vector<Button> QuizChoices_Winter1;
QuizChoices_Winter1.push_back(Button(100, 280, 900, 55, "A) The invention of more efficient of neural network models", LIGHTGRAY, SKYBLUE));
QuizChoices_Winter1.push_back(Button(100, 355, 900, 55, "B) A new technology came by and proved more importiant", LIGHTGRAY, SKYBLUE));
QuizChoices_Winter1.push_back(Button(100, 430, 900, 55, "C) The british goverment cut funding", LIGHTGRAY, SKYBLUE));
QuizChoices_Winter1.push_back(Button(100, 505, 900, 55, "D) Failure in partical use in the real world", LIGHTGRAY, SKYBLUE));

vector<Button> QuizChoices_Summer2;
QuizChoices_Summer2.push_back(Button(100, 280, 900, 55, "A) Development of larger parameter models", LIGHTGRAY, SKYBLUE));
QuizChoices_Summer2.push_back(Button(100, 355, 900, 55, "B) New ultra broad machinery", LIGHTGRAY, SKYBLUE));
QuizChoices_Summer2.push_back(Button(100, 430, 900, 55, "C) Expert Systems excitement that could have knowledge of many fields", LIGHTGRAY, SKYBLUE));
QuizChoices_Summer2.push_back(Button(100, 505, 900, 55, "D) AI now has general intelligence", LIGHTGRAY, SKYBLUE));

vector<Button> QuizChoices_Winter2;
QuizChoices_Winter2.push_back(Button(100, 280, 900, 55, "A) Workstations form Sum and Apple were cheeper", LIGHTGRAY, SKYBLUE));
QuizChoices_Winter2.push_back(Button(100, 355, 900, 55, "B) Expert Systems were good at edge cases, but were expensive", LIGHTGRAY, SKYBLUE));
QuizChoices_Winter2.push_back(Button(100, 430, 900, 55, "C) Maitnace of LISP machines were expensive and inconvenient", LIGHTGRAY, SKYBLUE));
QuizChoices_Winter2.push_back(Button(100, 505, 900, 55, "D) Japan's Fifth Generation hardware goals failed", LIGHTGRAY, SKYBLUE));

vector<Button> QuizChoices_Spring1;
QuizChoices_Spring1.push_back(Button(100, 280, 900, 55, "A) Correct answer", LIGHTGRAY, SKYBLUE));
QuizChoices_Spring1.push_back(Button(100, 355, 900, 55, "B) IBM's Deep Blue defeating Garry Kasparov in chess", LIGHTGRAY, SKYBLUE));
QuizChoices_Spring1.push_back(Button(100, 430, 900, 55, "C) AI shifted from learning from ahnd written rules and into learning form given data", LIGHTGRAY, SKYBLUE));
QuizChoices_Spring1.push_back(Button(100, 505, 900, 55, "D) Models got to the millions of parameters stage", LIGHTGRAY, SKYBLUE));

vector<Button> QuizChoices_Summer3;
QuizChoices_Summer3.push_back(Button(100, 280, 900, 55, "A) Excecive Energy consumnption", LIGHTGRAY, SKYBLUE));
QuizChoices_Summer3.push_back(Button(100, 355, 900, 55, "B) Data scraping of web pages", LIGHTGRAY, SKYBLUE));
QuizChoices_Summer3.push_back(Button(100, 430, 900, 55, "C) Invisible human labor", LIGHTGRAY, SKYBLUE));
QuizChoices_Summer3.push_back(Button(100, 505, 900, 55, "D) All off the Above", LIGHTGRAY, SKYBLUE));

int correctChoice_Summer1 = 1;
int correctChoice_Winter1 = 3;
int correctChoice_Summer2 = 2;
int correctChoice_Winter2 = 1;
int correctChoice_Spring1 = 2;
int correctChoice_Summer3 = 3;
    
SetTargetFPS(60);

while (!WindowShouldClose()){
        
if (Current_tab == 0) {
    for (int i = 0; i < StemButtons.size(); i++){
        bool isUnlocked = true;

        if (i == 1 && !Summer1Passed) {
            isUnlocked = false;
        }
        if (i == 2 && !Winter1Passed) {
            isUnlocked = false;
        }
        if (i == 3 && !Summer2Passed) {
            isUnlocked = false;
        }
        if (i == 4 && !Winter2Passed) {
            isUnlocked = false;
        }
        if (i == 5 && !Spring1Passed) {
            isUnlocked = false;
        }

        if (StemButtons[i].Clicked(isUnlocked)) {
            Current_tab = i + 1;
            TakingQuiz = false;
            QuizResult = "";
        }
    }
}

else{
    if (back_button.Clicked(true)){
        if (TakingQuiz){
            TakingQuiz = false;
        }
        else{
            Current_tab = 0;
        }
    }

if (Current_tab == 1){
    if (!TakingQuiz){
        if (StartQuizButton.Clicked(true)){
            TakingQuiz = true;
            QuizResult = "";
        }
    }
else{
    for (int i = 0; i < QuizChoices_Summer1.size(); i++){
        if (QuizChoices_Summer1[i].Clicked(true)){
            if (i == correctChoice_Summer1){
                QuizResult = "Winter 1 is now unlocked!";
                Summer1Passed = true;
            }
            else{
                QuizResult = "merp, wrong";
                }
            }
        }
    }
}
else if (Current_tab == 2){
    if (!TakingQuiz){
        if (StartQuizButton.Clicked(true)){
            TakingQuiz = true;
            QuizResult = "";
        }
    }
else{
    for (int i = 0; i < QuizChoices_Winter1.size(); i++){
        if (QuizChoices_Winter1[i].Clicked(true)){
            if (i == correctChoice_Winter1){
                QuizResult = "Summer 2 is now unlocked!";
                Winter1Passed = true;
            }
            else{
                QuizResult = "meerp, wrong";
                }
            }
        }
    }
}
else if (Current_tab == 3){
    if (!TakingQuiz){
        if (StartQuizButton.Clicked(true)){
            TakingQuiz = true;
            QuizResult = "";
        }
    }
else{
    for (int i = 0; i < QuizChoices_Summer2.size(); i++){
        if (QuizChoices_Summer2[i].Clicked(true)){
            if (i == correctChoice_Summer2){
                QuizResult = "Winter 2 is now unlocked!";
                Summer2Passed = true;
            }
            else{
                QuizResult = "meeerp, wrong";
                }
            }
        }
    }
}
else if (Current_tab == 4){
    if (!TakingQuiz){
        if (StartQuizButton.Clicked(true)){
            TakingQuiz = true;
            QuizResult = "";
        }
    }
else{
    for (int i = 0; i < QuizChoices_Winter2.size(); i++){
        if (QuizChoices_Winter2[i].Clicked(true)){
            if (i == correctChoice_Winter2){
                QuizResult = "Spring 1 is now unlocked!";
                Winter2Passed = true;
            }
            else{
                QuizResult = "meeeerp, wrong";
                }
            }
        }
    }
}
else if (Current_tab == 5){
    if (!TakingQuiz){
        if (StartQuizButton.Clicked(true)){
            TakingQuiz = true;
            QuizResult = "";
        }
    }
else{
    for (int i = 0; i < QuizChoices_Spring1.size(); i++){
        if (QuizChoices_Spring1[i].Clicked(true)){
            if (i == correctChoice_Spring1){
                QuizResult = "Summer 3 is now unlocked!";
                Spring1Passed = true;
            }
            else{
                QuizResult = "meeeeerp, wrong";
                }
            }
        }
    }
}
else if (Current_tab == 6){
    if (!TakingQuiz){
        if (StartQuizButton.Clicked(true)){
            TakingQuiz = true;
            QuizResult = "";
        }
    }
else{
    for (int i = 0; i < QuizChoices_Summer3.size(); i++){
        if (QuizChoices_Summer3[i].Clicked(true)){
            if (i == correctChoice_Summer3){
                QuizResult = "You finished all quizzes!";
                Summer3Passed = true;
            }
            else{
                QuizResult = "meeeeeerp, wrong";
                    }
                }
            }
        }
    }
}



BeginDrawing();

if (Current_tab == 0){
    ClearBackground(BLACK);

    // I made stars beacsue it looked so bad with a grey background
    if(Star_TimeHolder > .800f){
        Star_Radius.clear();
        for (int i = 0; i < stars.size(); i++){
            Star_Radius.push_back(GetRandomValue(1, 3));
        }
        Star_TimeHolder = 0;
    }
    for (int i = 0; i < stars.size(); i++){
        DrawCircleV(stars[i], Star_Radius[i], StarBlue);
    }

    DrawCircle(GetScreenWidth(), 0, 280, {255, 222, 56, 255});
    DrawLineEx({0, center_H}, {(float)GetScreenWidth(), center_H}, 6.0f, WHITE);

    for (int i = 0; i < StemButtons.size(); i++){

    float BottonCenX = StemButtons[i].Size.x + (StemButtonSize.x / 2);
    float BottonCenY = StemButtons[i].Size.y + (StemButtonSize.y / 2);

    DrawLineEx({BottonCenX, center_H}, { BottonCenX, BottonCenY }, 4.0f, WHITE);
    DrawCircle((int)BottonCenX, (int)center_H, 8.0f, WHITE);

    bool isUnlocked = true;

    if (i == 1 && !Summer1Passed) {
        isUnlocked = false;
    }
    if (i == 2 && !Winter1Passed) {
        isUnlocked = false;
    }
    if (i == 3 && !Summer2Passed) {
        isUnlocked = false;
    }
    if (i == 4 && !Winter2Passed) {
        isUnlocked = false;
    }
    if (i == 5 && !Spring1Passed) {
        isUnlocked = false;
    }

    StemButtons[i].Update(isUnlocked);
    }
}

else{
if (Current_tab == 1){
    ClearBackground(SummerYellow);
}
else if (Current_tab == 2){
    ClearBackground(WinterBlue);
}
else if (Current_tab == 3){
    ClearBackground(SummerYellow);
}
else if (Current_tab == 4){
    ClearBackground(WinterBlue);
}
else if (Current_tab == 5){
    ClearBackground(SpringGreen);
}
else{
    ClearBackground(SummerYellow);
}

back_button.Update(true);
DrawText(StemButtons[Current_tab - 1].Text.c_str(), 100, 100, 40, WHITE);

if (Current_tab == 1){
    if (!TakingQuiz){
        DrawText("Summer 1 Quiz :)", 100, 180, QuizFontSize, LIGHTGRAY);
        StartQuizButton.Update(true);

        Rectangle TextBoxSummer1 = {(float)(GetScreenWidth()/4) - 30.0f, 100, (float)(GetScreenWidth()*3)/4, 800.0f};
        DrawRectangleRec(TextBoxSummer1, GRAY);
        DrawText("1st AI Summer (1956-1973)", GetScreenWidth()/4, 200, 60, BLACK);
        DrawRectangleLinesEx(TextBoxSummer1, 9.0f, BLACK);
        DrawText(
            "Sparked by the 1956 Dartmouth Workshop and early DARPA funding,\n the 1st AI Summer was defined by intense optimism around symbolic\n reasoning and early neural models.  Pioneers built foundational\n systems like the Perceptron Mark I, ADALINE,  Logic Theorist,\n and ELIZA, operating at scales of just hundreds to thousands of parameters.\n Researchers tested logic-based  paradigms in simplified \"microworlds,\"\n convinced that human-level machine intelligence was only a generation away.\n'n Early successes in algebra problem solving, basic games, and pattern\n recognition fueled massive institutional contidence. That high expectation\n set the stage for an inevitable clash with real-world complexity.",
            GetScreenWidth()/4,
            300,
            30,
            BLACK
        );
    }
    else{
        DrawText("What events started the 1st AI Summer?", 100, 200, QuizFontSize, BLACK);

        for (int i = 0; i < QuizChoices_Summer1.size(); i++){
            QuizChoices_Summer1[i].Update(true);
        }

        if (QuizResult != ""){
            Color MessageColor;
            if (Summer1Passed){
                MessageColor = GREEN;
            }
            else{
                MessageColor = RED;
            }
            DrawText(QuizResult.c_str(), 100, 600, QuizFontSize, MessageColor);
        }
    }
}

else if (Current_tab == 2) {
    if (!TakingQuiz) {
        DrawText("Winter 1 Quiz :)", 100, 180, QuizFontSize, LIGHTGRAY);
        StartQuizButton.Update(true);

        Rectangle TextBoxWinter1 = {(float)(GetScreenWidth()/4) - 30.0f, 100, (float)(GetScreenWidth() * 3)/4, 800.0f};
        DrawRectangleRec(TextBoxWinter1, GRAY);
        DrawText("1st AI Winter (1974-1980)", GetScreenWidth()/4, 200, 60, BLACK);
        DrawRectangleLinesEx(TextBoxWinter1, 9.0f, BLACK);
        DrawText(
            "The 1st AI Winter arrived when early symbolic programs failed to scale\n beyond narrow toy environments into messy, real-world tasks.\n Critical evaluations-most notably the 1973 Lighthill Report and the SIR\n debate-exposed severe limitations in machine translation and\n combinatorics explosion. In response, DARPA and British funding agencies\n sharply cut financial support for general AI research. Parameter counts\n stagnated in the thousands as projects stalled under hardware\n limits and unfulfilled promises. The field entered a period of\n skepticism where simply using the term \"artificial intelligence\" made securing grants difficult.",
            GetScreenWidth()/4,
            300,
            30,
            BLACK);
    }
    else {
        DrawText("What triggered the funding cuts from DARPA and British agencies during the 1st AI Winter?", 100, 200, QuizFontSize, BLACK);
        for (int i = 0; i < QuizChoices_Winter1.size(); i++){
            QuizChoices_Winter1[i].Update(true);
        }
        if (QuizResult != ""){
            Color MessageColor;
            if (Winter1Passed){
                MessageColor = GREEN;
            }
            else{
                MessageColor = RED;
            }
            DrawText(QuizResult.c_str(), 100, 600, QuizFontSize, MessageColor);
        }
    }
}

else if (Current_tab == 3) {
    if (!TakingQuiz) {
        DrawText("Summer 2 Quiz :)", 100, 180, QuizFontSize, LIGHTGRAY);
        StartQuizButton.Update(true);

        Rectangle TextBoxSummer2 = {(float)(GetScreenWidth()/4) - 30.0f, 100, (float)(GetScreenWidth() * 3)/4, 800.0f};
        DrawRectangleRec(TextBoxSummer2, GRAY);
        DrawText("2nd AI Summer (1980-1987)", GetScreenWidth()/4, 200, 60, BLACK);
        DrawRectangleLinesEx(TextBoxSummer2, 9.0f, BLACK);
        DrawText(
            "Momentum returned during the 2nd AI Summer through commercial enthusiasm\n for Expert Systems, specialized LISP machines, and Japan's ambitious Fifth\n Generation Computer Systems project. Rather than chasing general intelligence,\n developers encoded narrow domain expertise into explicit it-then rule\n bases, pushing parameter scales into the hundreds of thousands and millions.\n Corporations poured money into rule-based software for medical diagnosis,\n financial analysis, and lexical databases like WordNet. Tailored symbolic\n hardware made large rule systems viable for enterprise deployment.\n For a few years, codifying human rules looked like a reliable commercial formula.",
            GetScreenWidth()/4,
            300,
            30,
            BLACK);
    }
    else {
        DrawText("Why did people get really invested back into AI?", 100, 200, QuizFontSize, BLACK);
        for (int i = 0; i < QuizChoices_Summer2.size(); i++){
            QuizChoices_Summer2[i].Update(true);
        }
        if (QuizResult != ""){
            Color MessageColor;
            if (Summer2Passed){
                MessageColor = GREEN;
            }
            else{
                MessageColor = RED;
            }
            DrawText(QuizResult.c_str(), 100, 600, QuizFontSize, MessageColor);
        }
    }
}
else if (Current_tab == 4) {
    if (!TakingQuiz) {
        DrawText("Winter 2 Quiz :)", 100, 180, QuizFontSize, LIGHTGRAY);
        StartQuizButton.Update(true);

        Rectangle TextBoxWinter2 = {(float)(GetScreenWidth()/4) - 30.0f, 100, (float)(GetScreenWidth() * 3)/4, 800.0f};
        DrawRectangleRec(TextBoxWinter2, GRAY);
        DrawText("2nd AI Winter (1987-1993)", GetScreenWidth()/4, 200, 60, BLACK);
        DrawRectangleLinesEx(TextBoxWinter2, 9.0f, BLACK);
        DrawText(
            "LISP machine market collapsed in 1987 alongside the eventual failure\n of Japan's Fifth Generation hardware goals. Desktop workstations from\n companies like Sun and Apple quickly outperformed expensive, dedicated\n AI hardware, undercutting specialized vendors. Meanwhile, expert\n systems proved brittle at edge cases and prohibitively expensive to update\n as rule bases grew complex. Enterprise buyers pulled back once maintenance\n costs outweighed practical returns. Once again, funding dried up and commercial hype gave way to disillusionment.",
            GetScreenWidth()/4,
            300,
            30,
            BLACK);
    }
    else {
        DrawText("Which one is not correct?", 100, 200, QuizFontSize, BLACK);
        for (int i = 0; i < QuizChoices_Winter2.size(); i++){
            QuizChoices_Winter2[i].Update(true);
        }
        if (QuizResult != ""){
            Color MessageColor;
            if (Winter2Passed){
                MessageColor = GREEN;
            }
            else{
                MessageColor = RED;
            }
            DrawText(QuizResult.c_str(), 100, 600, QuizFontSize, MessageColor);
        }
    }
}
else if (Current_tab == 5) {
    if (!TakingQuiz) {
        DrawText("Spring 1 Quiz :)", 100, 180, QuizFontSize, LIGHTGRAY);
        StartQuizButton.Update(true);

        Rectangle TextBoxSpring1 = {(float)(GetScreenWidth()/4) - 30.0f, 100, (float)(GetScreenWidth() * 3)/4, 800.0f};
        DrawRectangleRec(TextBoxSpring1, GRAY);
        DrawText("3rd AI Spring / Shift (1993-2010)", GetScreenWidth()/4, 200, 60, BLACK);
        DrawRectangleLinesEx(TextBoxSpring1, 9.0f, BLACK);
        DrawText(
            "Bridging the 2nd AI Winter and the modern generative boom, the\n 3rd AI Spring marked a quiet shift from hand-coded rules to data-driven\n machine learning. Driven by rising compute, larger datasets,\n and DARPA Grand Challenges, algorithms began learning statistical\n patterns directly from data. Landmark moments like IBM's Deep Blue\n defeating Garry Kasparov and early convolutional networks like LeNet-5\n pushed parameter counts into the millions and tens of millions. Researchers\n focused on practical subfields-vision, speech, and recommendation\n systems-often avoiding the \"AI\" label altogether. This steady progress\n laid the mathematical and computational foundation for deep learning.",
            GetScreenWidth()/4,
            300,
            30,
            BLACK);
    }
    else {
        DrawText("How did AI change fundamentaly?", 100, 200, QuizFontSize, BLACK);
        for (int i = 0; i < QuizChoices_Spring1.size(); i++){
            QuizChoices_Spring1[i].Update(true);
        }
        if (QuizResult != ""){
            Color MessageColor;
            if (Spring1Passed){
                MessageColor = GREEN;
            }
            else{
                MessageColor = RED;
            }
            DrawText(QuizResult.c_str(), 100, 600, QuizFontSize, MessageColor);
        }
    }
}
else if (Current_tab == 6) {
    if (!TakingQuiz) {
        DrawText("Summer 3 Quiz :)", 100, 180, QuizFontSize, LIGHTGRAY);
        StartQuizButton.Update(true);

        Rectangle TextBoxSummer3 = {(float)(GetScreenWidth()/4) - 30.0f, 100, (float)(GetScreenWidth() * 3)/4, 800.0f};
        DrawRectangleRec(TextBoxSummer3, GRAY);
        DrawText("3rd AI Summer (2010-Present)", GetScreenWidth()/4, 200, 60, BLACK);
        DrawRectangleLinesEx(TextBoxSummer3, 9.0f, BLACK);
        DrawText(
            "Fueled by massive datasets, GPU acceleration, and transformer architectures,\n the 3rd AI Summer triggered an unprecedented explosion in scale.\n Beginning with breakthroughs like ImageNet and expanding into GANs,\n disillusion models, and multimodal LLMS, parameter counts surged from\n billions to over 100 trillion. Modern systems now generate fluent text,\n  realistic imagery, code, and audio across industries at global scale.\n At the same time, Calculating Empires highlights the hidden costs behind\n this boom: massive energy consumption, large-scale data scraping, invisible\n human labor, and corporate consolidation. What started as academic\n pattern recognition has become capital-intensive planetary infrastructure.",
            GetScreenWidth()/4,
            300,
            30,
            BLACK);
    }
    else {
        DrawText("What is the cost of modern AI?", 100, 200, QuizFontSize, BLACK);
        for (int i = 0; i < QuizChoices_Summer3.size(); i++){
            QuizChoices_Summer3[i].Update(true);
        }
        if (QuizResult != ""){
            Color MessageColor;
            if (Summer3Passed){
                MessageColor = GREEN;
            }
            else{
                MessageColor = RED;
            }
            DrawText(QuizResult.c_str(), 100, 600, QuizFontSize, MessageColor);
                    }
                }
            }
        }
    EndDrawing();
    Star_TimeHolder += GetFrameTime();
}

    CloseWindow();
    return 0;
}