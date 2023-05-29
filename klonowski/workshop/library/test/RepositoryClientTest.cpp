//
// Created by Hubert Klonowski on 14/05/2023.
//
#include <boost/test/unit_test.hpp>
#include "repositories/StorageContainer.h"
#include "repositories/ClientRepository.h"

struct TestSuiteRepoClientFixture{
    StorageContainer sc;
    AddressPtr adr1,adr2;
    ClientPtr c1,c2;
    std::vector<RentPtr> c1Rents;
    TestSuiteRepoClientFixture() {
        adr1 = new Address("Lodz", "Gorna", "1");
        c1 = new Client("Adi","Nowak", "1231232131231", adr1, c1Rents);
        adr2 = new Address("Gdansk", "Torunska", "1A");
        c2 = new Client("Piernik", "Wodny", "5743973481", adr2, c1Rents);
    }

    ~TestSuiteRepoClientFixture() {
        delete adr1;
        delete c1;
        delete adr2;
        delete c2;
    }
};

bool pred_Walter(ClientPtr ptr) {
    return ptr->getFirstName() == "Walter";
}

BOOST_FIXTURE_TEST_SUITE(TestSuiteRepoClient, TestSuiteRepoClientFixture)
    BOOST_AUTO_TEST_CASE(ClientContainerGetTest){
        ClientRepository repo(sc.getClientRepo());
        BOOST_TEST(repo.get(0)->getClientInfo() == c1->getClientInfo());
    }

    BOOST_AUTO_TEST_CASE(ClientContainerGetNullTest){
        ClientRepository repo(sc.getClientRepo());
        BOOST_TEST(repo.get(2) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(ClientContainerAddTest){
        ClientRepository repo(sc.getClientRepo());
        repo.add(c2);
        BOOST_TEST(repo.get(2)->getClientInfo() == c2->getClientInfo());
        BOOST_TEST(repo.size() == 3);
    }
    BOOST_AUTO_TEST_CASE(ClientContainerAddNullTest){
        ClientRepository repo(sc.getClientRepo());
        repo.add(nullptr);
        BOOST_TEST(repo.get(2) == nullptr);
        BOOST_TEST(repo.size() == 2);
    }

    BOOST_AUTO_TEST_CASE(ClientContainerRemoveTest){
        ClientRepository repo(sc.getClientRepo());
        repo.remove(repo.get(1));
        BOOST_TEST(repo.get(0)->getClientInfo() == c1->getClientInfo());
        BOOST_TEST(repo.get(1) == nullptr);
        BOOST_TEST(repo.size() == 1);
    }

    BOOST_AUTO_TEST_CASE(ClientContainerRemoveNullTest){
        ClientRepository repo(sc.getClientRepo());
        repo.remove(nullptr);
        BOOST_TEST(repo.size() == 2);
    }

    BOOST_AUTO_TEST_CASE(ClientContainerReportTest){
        ClientRepository repo(sc.getClientRepo());
        repo.remove(repo.get(1));
        repo.add(c2);
        std::string info=c1->getClientInfo() + c2->getClientInfo();
        BOOST_TEST(repo.report() == info);
    }
    BOOST_AUTO_TEST_CASE(ClientContainerFindAllTest){
        ClientRepository repo(sc.getClientRepo());
        std::vector<ClientPtr> matchingClients = repo.findAll();
        ClientRepository matches(matchingClients);
        BOOST_TEST(repo.report() == matches.report());
    }
    BOOST_AUTO_TEST_CASE(ClientContainerFindByTest){
        ClientRepository repo(sc.getClientRepo());
        std::vector<ClientPtr> matchingClients = repo.findBy(pred_Walter);
        ClientRepository matches(matchingClients);
        BOOST_TEST(matches.size() == 1);
        BOOST_TEST(repo.get(0)->getClientInfo() == matches.report());
    }

BOOST_AUTO_TEST_SUITE_END();

