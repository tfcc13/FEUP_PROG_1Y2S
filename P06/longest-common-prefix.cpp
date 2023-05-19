/*
Write a C++ function string longest_prefix(const vector<string>& v) that, given a vector v of strings, returns the longest common prefix to all of the strings.

For example, if v contains "apple", "apply", "ape", and "april", then the longest common prefix is "ap". 
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;


string longest_prefix(const vector<string>& v) {
    
    int shortest = 1000;
    int size = v.size();
    char current;

    string result =  "";
    if (size == 0) return result;



    for (int i = 0; i < size; i++) {
        int k = v[i].length();
        if (k < shortest) {
            shortest = k;
        }
    }

    for (int j = 0; j <size;j++) {
    for (int i = 0; i< shortest; i++) {
        current = v[j][i];
        for (string s:v) {
            if (s[i] != current) return result;
        }
        result += current;

    }
    }
    return result;

}

int main() {
      // public tests (1 point each)
  {
    cout << "\"" << longest_prefix({ "apple", "apply", "ape", "april" }) << "\"\n";
  }  // -> "ap"
  {
    cout << "\"" << longest_prefix({ "ap", "apple", "apply", "ape", "april", "aq", "x" }) << "\"\n";
  }  // -> ""
  {
    cout << "\"" << longest_prefix({ "geezer", "geeksforgeeks", "geeks", "geek" }) << "\"\n";
  }  // -> "gee"
  {
    cout << "\"" << longest_prefix({ "sedatesingratiateconcomitant", "sedatesparleypoliteness", "sedateselbowsHahn", "sedatesgloweringimbecility's", "sedatesbuttershexing", "sedatesKwangju'smulch's", "sedatesunwiserN", "sedatesprepossessedboggles", "sedatesinterrelationshipdialings", "sedatesgropesNelsen's", "sedatesMayfaircondemnations" }) << "\"\n";
  }  // -> "sedates"
  {
    cout << "\"" << longest_prefix({ "symmetricstalwartscorn'flowers", "symmetricShetland'ssuccessfully", "symmetricreceiver'shipsteed", "symmetricGrailsflown", "symmetricpromenadingoutflank", "symmetricdrugg'ingseizure", "symmetricsanctumsove'rprinting", "symmetricCitroentransgr'essed", "symmetricdissembledwinging", "symmetric'recoupingCinderella" }) << "\"\n";
  }  // -> "symmetric"

  cout << endl;
  // private tests (10000 points each)
  {
    cout << "\"" << longest_prefix({ "ap", "apple", "apply", "ape", "april", "aq" }) << "\"\n";
  }  // -> "a"
  {
    cout << "\"" << longest_prefix({ "pepperywaltzmainframe", "pepperyghastlierfuddle", "pepperyaddedLori", "pepperyblintzfault", "pepperyhowdahmulch", "pepperyunfavorablyatrophy", "pepperyfluesrehiring", "pepperyRidetrellises", "pepperyretrievalstrumpets", "pepperyexertedinfallibly", "pepperyteletypeswiftness", "pepperyretreadedcanopy", "pepperycompetenonsupport", "pepperycatsupread", "pepperyschoolchildrencontravening", "pepperypouredleased", "pepperypeekaboothumbs", "pepperyescapeesmonarchical", "pepperyhypnotistshellion", "pepperysolidnessbanns", "pepperywhitewallscigarillo", "pepperyreenteringthicket", "pepperycommentingVirginia", "pepperySavoyarddisclosed", "pepperyBernadettethwarting", "pepperyhickeysani", "pepperyinternationalismblasphemies", "pepperystarryradiance", "pepperypeacockssmocks", "pepperyDoricBloom", "pepperypouncinghandicap", "pepperyHanukkahPraia", "pepperyunhookedJami", "pepperyAttleecellist", "pepperyhallmarkssnafus", "pepperysportswearadjutant", "pepperyChisinaucircumlocution", "pepperysymbolizesjowl", "pepperyreactioncyclotron", "pepperyionizertactic", "pepperyeugenicsColombo", "pepperyMaureenexhibitionism", "pepperyhairyinvocation", "pepperyefficacylooping", "pepperybirdseedcolonizers", "pepperybanishmentjitneys", "pepperydespisingnonsense", "pepperyblastoffposture", "pepperysprigprominent", "pepperyinstanceLeeward", "pepperyBantuerrata", "pepperyprejudiceAdriatic", "pepperyverbosepottiest" }) << "\"\n";
  }  // -> "peppery"
  {
    cout << "\"" << longest_prefix({ "confideRothschildcommentating", "confideextortsraging", "confideseminarOnegin", "confideanthologiesPeg", "confidewranglerionizer", "confideexcerptspiraled", "confideeverythingscents", "confidecompotedint", "confideenigmaticRamayana", "confideBelemnonrefillable", "confideBrainfrostings", "confideAriadnecommercialization", "confideaddictedforeplay", "confideveracitysullies", "confideBackusmodifiers", "confideWilfredadversary", "confideflexingtangent", "confidecountablyhallucinogenic", "confidedependenceepicure", "confideLillianbirdwatchers", "confideBelushiunabashed", "confidehotshotgoats", "confidechapterscadavers", "confideslopsagnosticism", "confidebereavementfiercely", "confidemotormouthsinessentials", "confidevitrioliceases", "confideslouchesStalinist", "confideHeineailment", "confidepacingracehorse", "confideAlarliming", "confidelynchingsmillennial", "confidefunnilyMadeira", "confidefillingsbreaches", "confidepitonlithium", "confidetempestuousJune", "confidebinderdivisors", "confidedifferentialspend", "confideramblemangroves", "confideterrorizedblob", "confideGoudaappeared", "confidefantasyingscorch", "confideanglerbishopric", "confidereflectsAdar", "confidefaintedcharlatan", "confideMetamuciltreasurers", "confidepickabackplows", "confideGromykocardinal", "confidehasheeshmainframe", "confidechastisinglongtime", "confidecocktailcommunication", "confidedefraudsjourneyman" }) << "\"\n";
  }  // -> "confide"
  {
    cout << "\"" << longest_prefix({ "radiatingsoakingSue", "radiatingcolandersorphans", "radiatingenviousnessdiphthongs", "radiatiposteritycaverns", "radiatingpointlessrepression", "radiatingstaffboggled", "radiatingswamitheme", "radiatingh", "radiatingwithdrawnsnigger", "radiatingTashaforty", "radiatingspritzedmilers", "radiatingballoonistrediscovering", "radiatingpostulatingSephardi", "radiatingleashesunfashionable", "radiatingaweunruliness", "radiatingVikingimpression", "radiatingdissatisfactionrefreshingly", "radiatingcamptally", "radiatingpointillismnostrum", "radiatingaglowtypo", "radiatingHoraciomaterialized", "radiatingBarlowmeanwhile", "radiatingnecromancersgilt", "radiatinggoldsmithbanns", "radiatingenormousnessmuttered", "radiatingpensionTuamotu", "radiatingsupervisionbond", "radiatingtiaraJared", "radiatingforbidstheoretic", "radiatingoutlivingtransferring", "radiatingappointeefettering", "radiatingHarveyGael", "radiatingdraftedindivisible", "radiatingHialeahswivel", "radiatingOkeechobeeunveiled", "radiatingArubadeplores", "radiatingmasonsKarol", "radiatingverbalcarouser", "radiatingaccidentalfoiling", "radiatingaconiteMcMahon", "radiatingconvictionChile", "radiatingpleasingstherapists", "radiatingmalehastily", "radiatingclangeddeceived", "radiatingimpolitelyseemliness", "radiatingmiasmasdragooned", "radiatingloopholeslum", "radiatingpreachierlewdest", "radiatingbevelledamaranths", "radiatingcrevassepurrs", "radiatingunderchargedoccupants", "radiatingwarlordFrancine", "radiatingcockmadwomen", "radiatingChangwagon", "radiatingtrumpbedder", "radiatingfogyslenderizing", "radiatingelephantinegruesomer", "radiatingmicroscopyruggeder", "radiatingmaterialshrived", "radiatingsemiprofessionalsreplied", "radiatingslideshowscustody", "radiatingRankinelopsided", "radiatingGerberGuerra", "radiatingperkinessDionysus", "radiatingdilutingaffected", "radiatingsachetHaiti", "radiatingmolestersPullman", "radiatingentailingZaporozhye", "radiatingchicorysilence", "radiatinglariatmotioning", "radiatingellstriated", "radiatingcessationconfab", "radiatingLouielumbar", "radiatingValdezchords", "radiatingspeciesinconsiderable", "radiatingColgateMcGee", "radiatingautobiographyrelegation", "radiatingProvençalbeatniks", "radiatingrabbimigrating", "radiatingredoublesThieu", "radiatingpillowcasecotter" }) << "\"\n";
  }  // -> "radiati"
  {
    cout << "\"" << longest_prefix({ "Elisabethtomatofirepower", "Elisabethattackerschickweed", "ElisabethJohannMarat", "Elisabethmultiplicationopportunist", "Elisabethimpresariossentences", "Elisabethhaughtiestrhetoric", "Elisabethdiscussburnoose", "Elisabethfiremaninshore", "ElisabethsupportableBhutan", "Elisabethpredatepill", "Elisabethstitchesvertebra", "Elisabethpresumingtenacity", "Elisabethquadrupleenquiry", "Elisabethstreetwalkersnetworked", "Elisabethcompanyscrew", "Elisabethshowpiecehelmet", "Elisabethhindquartershallot", "ElisabethTweedledumverbs", "ElisabethbacillusHolstein", "ElisabethWaksmansculpture", "ElisabethabilityBrahmins", "ElisabethrevoltedBradstreet", "ElisabethinfectionsDirac", "ElisabethsettleMycenae", "ElisabethseminariesColleen", "ElisabethvireoJamaicans", "Elisabethpluckmisbehave", "Elisabethextroversionships", "ElisabethRossinipossess", "ElisabethSamuelsonpitch" }) << "\"\n";
  }  // -> "Elisabeth"
  
  return 0; 

}