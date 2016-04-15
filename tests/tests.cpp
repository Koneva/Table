#include "gtest.h"
#include "classes.hpp"

//-------------------------------------------------------TabRecord-----------------------------------------------
TEST(TabRecord, create_table)
{
	TabRecord *table;
	ASSERT_NO_THROW(table = new TabRecord(1,"qw"));
}

TEST(TabRecord, can_get_key)
{
	TabRecord *table = new TabRecord(1,"qw");
	TKey k;
	ASSERT_NO_THROW(k = table -> GetKey());
}

TEST(TabRecord, true_key)
{
	TabRecord *table = new TabRecord(1,"qw");
	TKey k = table -> GetKey();
	EXPECT_EQ(k,1);
}

TEST(TabRecord, can_get_data)
{
	TabRecord *table = new TabRecord(1,"qw");
	TData* d;
	ASSERT_NO_THROW(d = table -> GetData());
}

TEST(TabRecord, true_data)
{
	TabRecord *table = new TabRecord(1,"qw");
	TData* d = table -> GetData();
	EXPECT_EQ(d,"qw");
}

//-------------------------------------------------------------Table-----------------------------------------------

//-------------------------------------------------------------ScanTable-------------------------------------------
