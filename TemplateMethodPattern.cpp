#include<iostream>
#include<string>

using namespace std;

// ___________________________________________
// 1. Base class defining the template metod
// ___________________________________________

class ModelTrainer {
public:
    // The template method - final so subclasses can't change the sequence
    void trainPipeline(const string& dataPath){
        loadData(dataPath);
        preprocessData();
        trainModel();       // subclass-specific
        evaluateModel();    // subclass-specific
        saveModel();         // subclass-specific or default
    }
protected:
    void loadData(const string& path){
        cout<<"[common] Loading dataset from "<<path<<"\n";
        // e.g. read CSV, image, etc.
    }

    virtual void preprocessData() {
        cout<< "[common] Splitting into train/test and normalizing\n";
    }

    virtual void trainModel() = 0; // must be implemented by subclass
    virtual void evaluateModel() = 0;

    // Provide a default save, but subclasss can override if needed
    virtual void saveModel() {
        cout<< "[common] Saving model to disk as default format\n";
    }
};

// ___________________________________________
// 2. Concrete subclass: Neural Network
// ___________________________________________
class NeuralNetworkTrainer: public ModelTrainer {
protected:
    void trainModel () override {
        cout<< "[NeuralNet] Training Neural Network for 100 eposhs\n";
        // pseudo-code: forward/backward passes, gradient descent....
    } 
    void evaluateModel() override {
        cout<< "[NeuralNet] Evaluating accuracy and loss on validation set\n";
    }
    void saveModel() override {
        cout<< "[NeuralNet] Serializing network weight to.h5 file\n";
    }
};

// ___________________________________________
// 3. Concrete subclass: Decision Tree
// ___________________________________________
class DecisionTreeTrainer : public ModelTrainer {
protected:
    // Use the default preprocessDate() (train/test spilt + normalize)

    void trainModel() override {
        cout<< "[DecisionTree] Building decision tree with max_depth=5\n";
        // pseudo-code: recursive splitting on features...
    }

    void evaluateModel() override {
        cout<< "[DecisionTree] Computing classification report (precision/recall)\n";
    }
    // Use the default saveModel()
};

// ___________________________________________
// 4. Usage
// ___________________________________________
int main() {
    cout<< "=== Neural Network Trainning ===\n";
    ModelTrainer* nnTrainer = new NeuralNetworkTrainer();
    nnTrainer->trainPipeline("data/images/");

    cout<< "\n=== Decision Tree Training ===\n";
    ModelTrainer* dtTrainer = new DecisionTreeTrainer();
    dtTrainer->trainPipeline("data/iris.csv");
    return 0;
}





// =================================================================================
//                                     OUTPUT
// =================================================================================

//               === Neural Network Trainning ===                                            
//               [common] Loading dataset from data/images/                                  
//               [common] Splitting into train/test and normalizing
//               [NeuralNet] Training Neural Network for 100 eposhs
//               [NeuralNet] Evaluating accuracy and loss on validation set
//               [NeuralNet] Serializing network weight to.h5 file
              
//               === Decision Tree Training ===
//               [common] Loading dataset from data/iris.csv
//               [common] Splitting into train/test and normalizing
//               [DecisionTree] Building decision tree with max_depth=5
//               [DecisionTree] Computing classification report (precision/recall)
//               [common] Saving model to disk as default format

// =================================================================================
