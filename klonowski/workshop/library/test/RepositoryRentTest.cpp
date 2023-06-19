//
// Created by Hubert Klonowski on 14/05/2023.
//
#include <boost/test/unit_test.hpp>
#include "repositories/StorageContainer.h"
#include "repositories/RentRepository.h"
#include "model/bicycle.h"

struct TestSuiteRepoRentFixture{
    StorageContainer sc;
    unsigned int id1 = 1;
    unsigned int id2 = 2;
    unsigned int id3 = 3;
    AddressPtr adr1,adr2;
    ClientPtr c1,c2;
    std::vector<RentPtr> c1Rents,c2Rents;
    VehiclePtr car1, car2, car3, car4;

    pt::ptime date1 = pt::ptime(boost::gregorian::date(2023,1,1));
    pt::ptime date2 = pt::ptime(boost::gregorian::date(2023,2,2));

    pt::ptime end=pt::ptime(boost::gregorian::date(2023,3,3), pt::hours(24)) ;
    RentPtr rent1;
    RentPtr rent2;
    RentPtr rent3;
    std::string plate1 = "ABCD1";
    std::string plate2 = "ABCD2";
    std::string plate3 = "ABCD3";
    std::string plate4 = "ABCD4";

    TestSuiteRepoRentFixture() {
        adr1 = new Address("Lodz", "Gorna", "1");
        c1 = new Client("Adi","Nowak", "1231232131231", adr1, c1Rents);
        adr2 = new Address("Gdansk", "Torunska", "1A");
        c2 = new Client("Piernik", "Wodny", "5743973481", adr2, c1Rents);
        car1 = new Bicycle(plate1, 1);
        car2 = new Bicycle(plate2, 2);
        car3 = new Bicycle(plate3, 3);
        car4 = new Bicycle(plate4, 4);
        rent1 = new Rent(id1, car1, c1, true, date1);

        rent1->endRent(end);

        rent2 = new Rent(id2, car2, c2, true, end);

        rent3 = new Rent(id3, car3, c2, true, date2);
    }
    ~TestSuiteRepoRentFixture() {
        delete adr1;
        delete c1;
        delete adr2;
        delete c2;
        delete car1;
        delete car2;
        delete car3;
        delete car4;
        delete rent1;
        delete rent2;
        delete rent3;
    }
};
bool pred_id1(RentPtr ptr) {
    return ptr->getId()==1;
}
BOOST_FIXTURE_TEST_SUITE(TestSuiteRepoRent, TestSuiteRepoRentFixture)
    BOOST_AUTO_TEST_CASE(RentContainerGetTest){
        RentRepository repo(sc.getRentRepo());
        BOOST_TEST(repo.get(0)->getRentInfo() == rent1->getRentInfo());
    }
    BOOST_AUTO_TEST_CASE(RentContainerGetNullTest){
        RentRepository repo(sc.getRentRepo());
        BOOST_TEST(repo.get(3) == nullptr);
    }
    BOOST_AUTO_TEST_CASE(RentContainerAddTest){
        RentRepository repo(sc.getRentRepo());
        repo.add(rent2);
        BOOST_TEST(repo.get(3)->getRentInfo() == rent2->getRentInfo());
        BOOST_TEST(repo.size() == 4);
    }
    BOOST_AUTO_TEST_CASE(RentContainerAddNullTest){
        RentRepository repo(sc.getRentRepo());
        repo.add(nullptr);
        BOOST_TEST(repo.get(3) == nullptr);
        BOOST_TEST(repo.size() == 3);
    }
    BOOST_AUTO_TEST_CASE(RentContainerRemoveTest){
        RentRepository repo(sc.getRentRepo());
        repo.remove(repo.get(0));
        BOOST_TEST(repo.get(0)->getRentInfo() == rent2->getRentInfo());
        BOOST_TEST(repo.get(2) == nullptr);
        BOOST_TEST(repo.size() == 2);
    }
    BOOST_AUTO_TEST_CASE(RentContainerRemoveNullTest){
        RentRepository repo(sc.getRentRepo());
        repo.remove(nullptr);
        BOOST_TEST(repo.size() == 3);
    }
    BOOST_AUTO_TEST_CASE(RentContainerReportTest){
        RentRepository repo(sc.getRentRepo());
        repo.remove(repo.get(2));
        repo.add(rent3);
        std::string info=rent1->getRentInfo()+rent2->getRentInfo()+rent3->getRentInfo();
        BOOST_TEST(repo.report()==info);
    }
    BOOST_AUTO_TEST_CASE(RentContainerFindAllTest){
        RentRepository repo(sc.getRentRepo());
        std::vector<RentPtr> matchingRents=repo.findAll();
        RentRepository matches(matchingRents);
        BOOST_TEST(repo.report()==matches.report());
    }
    BOOST_AUTO_TEST_CASE(RentContainerFindByTest){
        RentRepository repo(sc.getRentRepo());
        std::vector<RentPtr> matchingRents=repo.findBy(pred_id1);
        RentRepository matches(matchingRents);
        BOOST_TEST(matches.size() == 1);
        BOOST_TEST(repo.get(0)->getRentInfo() == matches.report());
    }
BOOST_AUTO_TEST_SUITE_END();