//
// Created by Hubert Klonowski on 14/05/2023.
//
#include <boost/test/unit_test.hpp>
#include "repositories/StorageContainer.h"
#include "repositories/VehicleRepository.h"
#include "model/bicycle.h"

struct TestSuiteRepoVehicleFixture{
    StorageContainer sc;
    VehiclePtr car1;
    VehiclePtr car2;
    VehiclePtr car3;
    VehiclePtr car4;
    std::string plate1 = "ABCD1";
    std::string plate2 = "ABCD2";
    std::string plate3 = "ABCD3";
    std::string plate4 = "ABCD4";
    TestSuiteRepoVehicleFixture() {
        car1 = new Bicycle(plate1, 1);
        car2 = new Bicycle(plate2, 2);
        car3 = new Bicycle(plate3, 3);
        car4 = new Bicycle(plate4, 4);
    }
    ~TestSuiteRepoVehicleFixture() {
        delete car1;
        delete car2;
        delete car3;
        delete car4;
    }
};
bool pred_price50(VehiclePtr ptr) {
    return ptr->getBasePrice() == 30;
}
BOOST_FIXTURE_TEST_SUITE(TestSuiteRepoVehicle, TestSuiteRepoVehicleFixture)
    BOOST_AUTO_TEST_CASE(VehicleContainer_getTest){
        VehicleRepository repo(sc.getVehicleRepo());
        BOOST_TEST(repo.get(0)->getVehicleInfo() == car1->getVehicleInfo());
    }
    BOOST_AUTO_TEST_CASE(VehicleContainerGetNullTest){
        VehicleRepository repo(sc.getVehicleRepo());
        BOOST_TEST(repo.get(2)== nullptr);
    }
    BOOST_AUTO_TEST_CASE(VehicleContainerAddTest){
        VehicleRepository repo(sc.getVehicleRepo());
        repo.add(car2);
        BOOST_TEST(repo.get(2)->getVehicleInfo() == car2->getVehicleInfo());
        BOOST_TEST(repo.size()== 3);
    }
    BOOST_AUTO_TEST_CASE(VehicleContainerAddNullTest){
        VehicleRepository repo(sc.getVehicleRepo());
        repo.add(nullptr);
        BOOST_TEST(repo.get(2) == nullptr);
        BOOST_TEST(repo.size() == 2);
    }
    BOOST_AUTO_TEST_CASE(VehicleContainerRemoveTest){
        VehicleRepository repo(sc.getVehicleRepo());
        repo.remove(repo.get(0));
        BOOST_TEST(repo.get(0)->getVehicleInfo() == car3->getVehicleInfo());
        BOOST_TEST(repo.get(1) == nullptr);
        BOOST_TEST(repo.size() == 1);
    }
    BOOST_AUTO_TEST_CASE(VehicleContainerRemoveNullTest){
        VehicleRepository repo(sc.getVehicleRepo());
        repo.remove(nullptr);
        BOOST_TEST(repo.size() == 2);
    }
    BOOST_AUTO_TEST_CASE(VehicleContainerReportTest){
        VehicleRepository repo(sc.getVehicleRepo());
        repo.remove(repo.get(1));
        repo.add(car4);
        std::string info = car1->getVehicleInfo() + car4->getVehicleInfo();
        BOOST_TEST(repo.report() == info);
    }
    BOOST_AUTO_TEST_CASE(VehicleContainerFindAllTest){
        VehicleRepository repo(sc.getVehicleRepo());
        std::vector<VehiclePtr> matchingVehicles = repo.findAll();
        VehicleRepository matches(matchingVehicles);
        BOOST_TEST(repo.report() == matches.report());
    }
    BOOST_AUTO_TEST_CASE(VehicleContainerFindByTest){
        VehicleRepository repo(sc.getVehicleRepo());
        std::vector<VehiclePtr> matchingVehicles=repo.findBy(pred_price50);
        VehicleRepository matches(matchingVehicles);
        BOOST_TEST(matches.size() == 1);
        BOOST_TEST(repo.get(1)->getVehicleInfo() == matches.report());
    }

BOOST_AUTO_TEST_SUITE_END();