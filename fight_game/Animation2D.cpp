#include "Animation2D.h"


Animation2D::Animation2D(Vec4 newframe, float speed) : anim_cursor(0),
current_frame_indx(0),
speed(speed)
{
	_frames = new vector<Vec4*>;
	Vec4 *frame =new Vec4(newframe.x, newframe.y, newframe.z, newframe.w);
	_frames->push_back(frame);
	frames_count = (int)_frames->size();
}


Animation2D::Animation2D(const char * filename, float speed) : anim_cursor(0),
current_frame_indx(0),
speed(speed)
{

	FILE* fp = nullptr;
	const int bufferlen = 255;
	char line[bufferlen];
	fopen_s(&fp, filename, "r");
	if (fp == nullptr)
	{
		printf("erorr in reading animation file \n");
	}
	else
	{
		_frames = new vector<Vec4*>;

		while (fgets(line, bufferlen, fp))
		{
			vector<int> result;

			stringstream ss(line);
			string token;
			while (getline(ss, token, ','))
			{
				result.push_back(stoi(token));
			}


			Vec4 *frame = new Vec4(result[0], result[1], result[2], result[3]);
			_frames->push_back(frame);




		}
	}
	frames_count = (int)_frames->size();
	fclose(fp);

}

Animation2D::~Animation2D()
{
}
//Vec4 TextureCutSetting ->textureWidth textureHeight heightCut  widthCut
std::vector<Vec4 *>* Animation2D::getNormallizeFramesArray(Vec4 TextureCutSetting)
{
	_normalizeFrames = new vector<Vec4*>;
	for (std::vector<Vec4*>::iterator iterator = _frames->begin(); iterator != _frames->end(); iterator++) {
		Vec4 *frames = *iterator;
		float x = frames->x / TextureCutSetting.x / TextureCutSetting.w;
		float y = frames->y / TextureCutSetting.y / TextureCutSetting.z;
		float z = frames->z / TextureCutSetting.x / TextureCutSetting.w;
		float w = frames->w / TextureCutSetting.y / TextureCutSetting.z;
		Vec4 *temp = new Vec4(x, y, z, w);
		_normalizeFrames->push_back(temp);

	}

	return _normalizeFrames;
}

void Animation2D::setvertexBufferArray(std::vector<VertexBuffer*>* vertexBufferArray)
{
	_vertexBufferArray = new std::vector<VertexBuffer*>;
	_vertexBufferArray = vertexBufferArray;
}


void Animation2D::play(double deltatime)
{
	anim_cursor += deltatime;

	if (anim_cursor > speed)
	{
		current_frame_indx = current_frame_indx + 1;
		if (current_frame_indx >= frames_count)current_frame_indx = 0;
		anim_cursor = 0;
	}


	//cout << current_frame_indx  ;
	_vertexBufferArray->at(current_frame_indx)->configureVertexAttributes();
	_vertexBufferArray->at(current_frame_indx)->renderVertexBuffer();

	//cout << current_frame_indx<<endl;
	
}
