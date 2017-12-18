#pragma once
#ifndef __GLMESH_H
#define __GLMESH_H

#include <string>
#include "VectorMatrix.h"
#include "OpenGL.h"
#include "GLShader.h"
#include "GLTexture.h"

class GLMesh
{
private:
	int posbuffer = -1, nmlbuffer = -1, tgtbuffer = -1, bnmbuffer = -1, texcoordbuffer = -1, idxbuffer = -1;
	int numvertices, numindices;
	PrimitiveType primitivetype;

public:
	GLMesh(int numvertices, int numindices, Vector3* positions, Vector3* normals = NULL, Vector3* tangents = NULL, Vector3* binormals = NULL, Vector2* texcoords = NULL, int* indices = NULL, PrimitiveType _primitivetype = 0xFFFFFFFF)
	{
		if (positions != NULL) // Mesh vertex positions array can't be NULL
			Reset(numvertices, numindices, positions, normals, tangents, binormals, texcoords, indices, _primitivetype);
	}

	void Free()
	{
		if (posbuffer != -1)
		{
			GL.DeleteBuffer(posbuffer);
			posbuffer = -1;
		}
		if (nmlbuffer != -1)
		{
			GL.DeleteBuffer(nmlbuffer);
			nmlbuffer = -1;
		}
		if (tgtbuffer != -1)
		{
			GL.DeleteBuffer(tgtbuffer);
			tgtbuffer = -1;
		}
		if (bnmbuffer != -1)
		{
			GL.DeleteBuffer(bnmbuffer);
			bnmbuffer = -1;
		}
		if (texcoordbuffer != -1)
		{
			GL.DeleteBuffer(texcoordbuffer);
			texcoordbuffer = -1;
		}
		if (idxbuffer != -1)
		{
			GL.DeleteBuffer(idxbuffer);
			idxbuffer = -1;
		}
	}

	void Reset(int numvertices, int numindices, Vector3* positions, Vector3* normals = NULL, Vector3* tangents = NULL, Vector3* binormals = NULL, Vector2* texcoords = NULL, int* indices = NULL, PrimitiveType _primitivetype = 0xFFFFFFFF)
	{
		this->numvertices = numvertices;
		this->numindices = 0;

		if (posbuffer == -1)
			posbuffer = GL.GenBuffer();
		GL.BindBuffer(BufferTarget::ArrayBuffer, posbuffer);
		GL.BufferData(BufferTarget::ArrayBuffer, numvertices * 3 * sizeof(float), positions, BufferUsageHint::StaticDraw);
		if (normals != NULL)
		{
			if (nmlbuffer == -1)
				nmlbuffer = GL.GenBuffer();
			GL.BindBuffer(BufferTarget::ArrayBuffer, nmlbuffer);
			GL.BufferData(BufferTarget::ArrayBuffer, numvertices * 3 * sizeof(float), normals, BufferUsageHint::StaticDraw);
		}
		else if (nmlbuffer != -1)
			GL.DeleteBuffer(nmlbuffer);
		if (tangents != NULL)
		{
			if (tgtbuffer == -1)
				tgtbuffer = GL.GenBuffer();
			GL.BindBuffer(BufferTarget::ArrayBuffer, tgtbuffer);
			GL.BufferData(BufferTarget::ArrayBuffer, numvertices * 3 * sizeof(float), tangents, BufferUsageHint::StaticDraw);
		}
		else if (tgtbuffer != -1)
			GL.DeleteBuffer(tgtbuffer);
		if (binormals != NULL)
		{
			if (bnmbuffer == -1)
				bnmbuffer = GL.GenBuffer();
			GL.BindBuffer(BufferTarget::ArrayBuffer, bnmbuffer);
			GL.BufferData(BufferTarget::ArrayBuffer, numvertices * 3 * sizeof(float), binormals, BufferUsageHint::StaticDraw);
		}
		else if (bnmbuffer != -1)
			GL.DeleteBuffer(bnmbuffer);
		if (texcoords != NULL)
		{
			if (texcoordbuffer == -1)
				texcoordbuffer = GL.GenBuffer();
			GL.BindBuffer(BufferTarget::ArrayBuffer, texcoordbuffer);
			GL.BufferData(BufferTarget::ArrayBuffer, numvertices * 2 * sizeof(float), texcoords, BufferUsageHint::StaticDraw);
		}
		else if (texcoordbuffer != -1)
			GL.DeleteBuffer(texcoordbuffer);
		if (indices != NULL)
		{
			if (idxbuffer == -1)
				idxbuffer = GL.GenBuffer();
			GL.BindBuffer(BufferTarget::ElementArrayBuffer, idxbuffer);
			GL.BufferData(BufferTarget::ElementArrayBuffer, numindices * sizeof(int), indices, BufferUsageHint::StaticDraw);
			this->numindices = numindices;
			if (_primitivetype == 0xFFFFFFFF)
				_primitivetype = PrimitiveType::Triangles; // Default primitive type for indexed geometry is TRIANGLES
		}
		else
		{
			if (idxbuffer != -1)
				GL.DeleteBuffer(idxbuffer);
			if (_primitivetype == 0xFFFFFFFF)
				_primitivetype = PrimitiveType::TriangleStrip; // Default primitive type for non-indexed geometry is TRIANGLE_STRIP
		}
		primitivetype = _primitivetype;
	}

	void Bind(GLShader* shader, GLTexture* texture = NULL, GLTexture* texture2 = NULL, GLTexture* texture3 = NULL, GLTexture* texture4 = NULL)
	{
		if (posbuffer == -1) // Mesh without vertex positions can't be rendered
			return;

		/*for(var i = 0; i < 16; i++)
		GL.DisableVertexAttribArray(i);

		GL.EnableVertexAttribArray(sdr.vertexPositionAttribute);*/
		GL.BindBuffer(BufferTarget::ArrayBuffer, posbuffer);
		GL.EnableClientState(ArrayCap::VertexArray);
		GL.VertexPointer(3, VertexPointerType::Float, 0, NULL);
		/*GL.VertexAttribPointer(sdr.vertexPositionAttribute, 3, VertexAttribType.Float, false, 0, 0);*/
		if (nmlbuffer != -1 /*&& sdr.vertexNormalAttribute != -1*/)
		{
			/*GL.EnableVertexAttribArray(sdr.vertexNormalAttribute);*/
			GL.BindBuffer(BufferTarget::ArrayBuffer, nmlbuffer);
			/*GL.VertexAttribPointer(sdr.vertexNormalAttribute, 3, gl.FLOAT, false, 0, 0);*/
		}
		/*if(tgtbuffer != -1 && sdr.vertexTangentAttribute != -1)
		{
		GL.EnableVertexAttribArray(sdr.vertexTangentAttribute);
		GL.BindBuffer(BufferTarget::ArrayBuffer, tgtbuffer);
		GL.VertexAttribPointer(sdr.vertexTangentAttribute, 3, gl.FLOAT, false, 0, 0);
		}
		if(bnmbuffer != -1 && sdr.vertexBinormalAttribute != -1)
		{
		GL.EnableVertexAttribArray(sdr.vertexBinormalAttribute);
		GL.BindBuffer(BufferTarget::ArrayBuffer, bnmbuffer);
		GL.VertexAttribPointer(sdr.vertexBinormalAttribute, 3, gl.FLOAT, false, 0, 0);
		}*/
		if (texcoordbuffer != -1 && shader->defattrs.texcoord != -1)
		{
			GL.EnableVertexAttribArray(shader->defattrs.texcoord);
			GL.BindBuffer(BufferTarget::ArrayBuffer, texcoordbuffer);
			GL.VertexAttribPointer(shader->defattrs.texcoord, 2, VertexAttribPointerType::Float, false, 0, 0);
		}
		if (texture != NULL)
		{
			GL.ActiveTexture(TextureUnit::Texture0);
			texture->Bind();
			if (shader != NULL)
				shader->SetTexture(0);
		}
		if (texture2 != NULL)
		{
			GL.ActiveTexture(TextureUnit::Texture1);
			texture2->Bind();
			if (shader != NULL)
				shader->SetTexture(1);
		}
		if (texture3 != NULL)
		{
			GL.ActiveTexture(TextureUnit::Texture2);
			texture3->Bind();
			if (shader != NULL)
				shader->SetTexture(2);
		}
		if (texture4 != NULL)
		{
			GL.ActiveTexture(TextureUnit::Texture3);
			texture4->Bind();
			if (shader != NULL)
				shader->SetTexture(3);
		}
		if (idxbuffer != -1)
			GL.BindBuffer(BufferTarget::ElementArrayBuffer, idxbuffer);
	}

	void Draw() const
	{
		if (posbuffer == -1) // Mesh without vertex positions can't be rendered
			return;

		if (idxbuffer != -1)
			GL.DrawElements(primitivetype, numindices, DrawElementsType::UnsignedInt, (GLvoid*)0); //EDIT untested
		else
			GL.DrawArrays(primitivetype, 0, numvertices);
	}

	void Draw(int start, int count) const
	{
		if (posbuffer == -1) // Mesh without vertex positions can't be rendered
			return;

		if (idxbuffer != -1)
			GL.DrawElements(primitivetype, count, DrawElementsType::UnsignedInt, (GLvoid*)(start * sizeof(GLuint))); //EDIT untested
		else
			GL.DrawArrays(primitivetype, start, count);
	}
};

class GLDynamicMesh
{
private:
	int numvertices, posbuffer;
	PrimitiveType primitivetype;

public:
	GLDynamicMesh(int numvertices)
	{
		this->numvertices = numvertices;
		posbuffer = GL.GenBuffer();
	}
	void Bind(Vector3* vertices, PrimitiveType primitivetype)
	{
		GL.BindBuffer(BufferTarget::ArrayBuffer, posbuffer);
		GL.EnableClientState(ArrayCap::VertexArray);
		GL.VertexPointer(3, VertexPointerType::Float, 0, NULL);
		GL.BufferData(BufferTarget::ArrayBuffer, numvertices * 3 * sizeof(float), vertices, BufferUsageHint::DynamicDraw);
		this->primitivetype = primitivetype;
	}
	void Draw() const
	{
		GL.DrawArrays(primitivetype, 0, numvertices);
	}
};

#endif