#include <stdio.h>
#include <stdlib.h>
// struct BLOCK
struct BLOCK
{
	short value;
	int   position;
};
const int N = 1005;
// CRLEImage
// class for run length encoded image
class CRLEImage
{
private:
	BLOCK m_data[N];
	int   m_count;
	int   m_width;
 
public:
	// constructor
	CRLEImage() : m_count(0), m_width(0)
	{
		m_data[0].position = 0;
		m_data[0].value	   = -1;
	}
	// Scan
	bool Scan()
	{
		int width, value, run_length;
		scanf("%d", &width);
		if( width == 0 ) {
			printf("0\n");
			return false;
		}
		m_width = width;
		int i = 1, index = 0;
		while(true)
		{
			scanf("%d %d", &value, &run_length);
			if( value == 0 && run_length == 0)
				break;
			index += run_length;
			set_block(i, (short)value, index);
			++i;
		}
		m_count = i-1;
		return true;
	}
	// Process
	void Process()
	{
		printf("%d\n", m_width);
		short last_edge = calculate_edge(1, 1), edge;
		int last_idx = 1, idx = 2;
		for(int i = 1; i <= m_count; ++i)
		{
			while(idx <= m_data[i].position)
			{
				edge = calculate_edge(idx, i);
				// if edge value change
				if(edge != last_edge)
				{
					printf("%d %d\n", (int)last_edge, (idx - last_idx));
					last_idx = idx;
					last_edge = edge;
				}
				// same pixels in consecutive rows
				if(last_edge == 0 && idx - m_data[i-1].position > m_width + 1
								  && m_data[i].position - idx > m_width)
					idx = m_data[i].position - m_width;
				else ++idx;
				// same pixels in consecutive columns
				if(idx%m_width > 2 )
				{
					int same_length = m_width-1;
					int idx_arr[3] = { idx-m_width-2, idx-2, idx+m_width-2 };
					for( int j = 0; j < 3; ++j )
					{
						int location, temp;
						search_pixel(idx_arr[j], i, (idx_arr[j]<idx), location);
						if(location > 0)
						{
							temp  = m_data[location].position - idx_arr[j];
							if(temp < same_length)
								same_length = temp;
						}
					}
					if(same_length > 2)
						idx += (same_length-2);
				}
			}
		}
		printf("%d %d\n", (int)edge, (idx - last_idx));
		printf("0 0\n");
	}
 
private:
	// set block
	void set_block(int index, short value, int position)
	{
		m_data[index].value = value;
		m_data[index].position = position;
	}
	// search pixel
	short search_pixel(int idx, int block, bool bBackward, int& location)
	{
		if(idx < 1 || idx > m_data[m_count].position)
		{
			location = -1;
			return 0;
		}
		int i = block;
		if(bBackward)
		{
			for(i = block-1; i >= 0; --i)
				if(idx > m_data[i].position)
				{
					location = i+1;				
					return m_data[i+1].value;
				}
		}
		else
		{
			for(i = block; i <= m_count; ++i)
				if(idx <= m_data[i].position)
				{
					location = i;
					return m_data[i].value;
				}
		}
	}
	// calculate edge
	short calculate_edge(int idx, int block)
	{
		bool flag[8]; // does neighbor exist
		for(int i = 0; i < 8; ++i)
			flag[i] = true;
		// top
		if((idx - 1)/m_width == 0) 
			flag[0] = flag[1] = flag[2] = false;
		// bottom
		if(idx + m_width > m_data[m_count].position) 
			flag[5] = flag[6] = flag[7] = false;
		// left (especially when width is 1)
		if(m_width == 1 || idx % m_width  == 1 )
			flag[0] = flag[3] = flag[5] = false;
		// right
		if(idx % m_width == 0 )
			flag[2] = flag[4] = flag[7] = false;
		// valid neighbor
		short base = m_data[block].value;
		short edge = 0;
		int nidx; // index of neighbor short
		for(int i = 0; i < 8; ++i)
			if(flag[i])
			{
				switch(i)
				{
				case 0:
				case 1:
				case 2:
					nidx = idx - m_width + i - 1;
					break;
				case 3:
					nidx = idx - 1;
					break;
				case 4:
					nidx = idx + 1;
					break;
				default:
					nidx = idx + m_width + i - 6;
				}
				short neighbor;
				int location;
				neighbor = search_pixel(nidx, block, (nidx<idx), location);
				short temp = ((neighbor > base) ? (neighbor - base) : (base - neighbor));
				if(temp > edge)
					edge = temp;
			}
		return edge;
	}
};
// entry point
int main()
{
	CRLEImage image;
	while( image.Scan() )
		image.Process();
	return 0;
}