#include <iostream>

class MlModel
{
public:
    virtual void applyAlgo() final
    {
        readData();
        trainModel();
        writeData();
    } // Template method
private:
    virtual void readData()
    {
        std::cout << "readData" << '\n';
    } // readData is same for all MlModels

    virtual void trainModel() = 0; // Different for each Model
    virtual void writeData()
    {
        std::cout << "writeData" << '\n';
    } // writeData is same for MlModels
};


class LinearRegression : public MlModel
{
private:
    void trainModel() override
    {
        std::cout << "Applying Liner Regression" << '\n'; // Step adapted by the child class
    }
};

class Ann : public MlModel
{
private:
    void trainModel() override
    {
        std::cout << "Applying Artificial neural network" << '\n'; // Step adapted by the child class
    }
};


int main()
{

    std::cout << '\n';

    MlModel *model = new LinearRegression;
    model->applyAlgo();

    std::cout << "\n\n";

    model = new Ann;
    model->applyAlgo();
}
